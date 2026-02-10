# MiniThreadShell

## 📋 Project Overview
**MiniThreadShell** is a desktop application that blends powerful command-line functionality with a user-friendly graphical interface. Built using **Tkinter**, it allows users to run terminal commands, view styled outputs, log activity to Excel, analyze usage with Matplotlib, and upload logs to an AWS S3 bucket.

A unique feature of this project is its multi-threaded shell component written in **C**, which Python interacts with through a compiled executable built using a **Makefile**.

## 🏗️ System Architecture
The application integrates several layers to provide a cohesive experience:
* **Shell Layer**: A multi-threaded C-based shell handling core execution logic.
* **Application Layer**: Python logic using `subprocess` and `Popen` to bridge the C executable and the GUI.
* **Data Layer**: Local persistence via **Excel (openpyxl)** and cloud storage via **AWS S3 (boto3)**.
* **Visualization Layer**: Command usage analysis powered by **Matplotlib**.

## 🛠️ Tech Stack
* **Languages**: Python 3.12.4, C.
* **GUI Framework**: Tkinter.
* **Libraries**:
    * `openpyxl`: For Excel file creation and management.
    * `matplotlib`: For generating visual command usage statistics.
    * `boto3`: For seamless AWS S3 integration.
* **Environment**: Developed in Visual Studio Code on macOS.

## 🚀 Key Features
* **Hybrid Interface**: Execute shell commands from a Tkinter GUI with dedicated areas for output and errors.
* **Automated Logging**: Logs every command and its output into a structured Excel file (`command_log.xlsx`) with timestamps.
* **Cloud Integration**: Verification of Excel log uploads to a designated AWS S3 bucket.
* **Usage Analytics**: Real-time bar charts showing the "Top 5 Most Used Commands" to track session activity.
* **Security**: Password-protected admin features and secure handling of cloud credentials.

## 📊 Future Work
* **System Monitoring**: Adding real-time system resource graphs for CPU and RAM.
* **Batch Execution**: Enabling command scheduling or batch execution.
* **Advanced Auth**: Integrating user authentication using tokens instead of plain passwords.
* **Export Options**: Providing CSV export and JSON-based configuration.

## 📚 References
* [Python Documentation](https://docs.python.org/3/)
* [Tkinter Documentation](https://tkdocs.com)
* [OpenPyXL (Excel) Docs](https://openpyxl.readthedocs.io/)
* [Boto3 (AWS) Docs](https://boto3.amazonaws.com/)
* [Matplotlib Documentation](https://matplotlib.org/)
