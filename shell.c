#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LEN 100
pthread_mutex_t lock;

void* run_command(void* arg) 
{
    char* cmd = (char*)arg;
    char* args[10];
    int i = 0;

    args[i] = strtok(cmd, " \n");
    while (args[i] != NULL && i < 9) 
    {
        args[++i] = strtok(NULL, " \n");
    }

    if (args[0] == NULL) return NULL;

    pthread_mutex_lock(&lock);

    pid_t pid = fork();
    if (pid == 0) 
    {
        execvp(args[0], args);
        perror("execvp failed");
        exit(1);
    } 
    else 
    {
        wait(NULL);
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() 
{
    char input[MAX_CMD_LEN];

    pthread_mutex_init(&lock, NULL);

    while (1) 
    {
        printf("MiniThreadShell$ ");
        fgets(input, MAX_CMD_LEN, stdin);

        if (strncmp(input, "exit", 4) == 0)
            break;

        pthread_t tid;
        char* cmd_copy = strdup(input);
        pthread_create(&tid, NULL, run_command, cmd_copy);
        pthread_join(tid, NULL);
        free(cmd_copy);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}

