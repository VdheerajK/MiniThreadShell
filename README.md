MiniThreadShell: GUI-Integrated Multi-threaded Shell

MiniThreadShell is a desktop application that bridges the gap between low-level system interaction and a modern graphical user interface. Developed to simplify command-line operations, the project integrates a multi-threaded C backend for core shell functionality with a Python frontend for visualization, logging, and cloud synchronization.

_____________________________________


🚀 Key Features
Dual-Language Architecture: Combines the performance of a multi-threaded C shell with the flexibility of a Python Tkinter GUI.

Automated Data Logging: Captures all terminal commands and outputs into an Excel (.xlsx) file for session auditing.



Cloud Persistence: Features one-click synchronization to Amazon S3 using Boto3, ensuring logs are securely backed up in the cloud.




Usage Analytics: Built-in data visualization using Matplotlib to analyze and graph the frequency of command usage.





System Security: Implements password-protected admin features and handles cloud credentials securely via environment variables.

_____________________________________

🛠️ Technical Stack
Frontend: Python (Tkinter).


Backend: C (Multi-threading), Python (Subprocess/Popen).




Cloud: AWS S3 (Boto3 SDK).



Data/Analytics: Matplotlib (Visualization), OpenPyXL (Excel automation).



Build System: Makefile for compiled C executables.

_____________________________________


🏗️ Architecture & Implementation
The application utilizes a 3-tier logic to process user requests:

UI Layer: A Tkinter entry field captures shell commands and displays styled terminal output.


Process Layer: Python uses Popen to communicate with a compiled C executable (./shell), which executes commands at the system level.


Data Layer: Activity is logged via log_to_excel() and uploaded via upload_to_s3() to a designated AWS bucket (dheeraj-cli-storage-2025).


_____________________________________


🔧 Installation & Setup
Clone the repository:

Bash
git clone https://github.com/VdheerajK/MiniThreadShell.git
cd MiniThreadShell
Compile the C Backend:

Bash
make
Configure Environment Variables: Set your AWS_ACCESS_KEY_ID and AWS_SECRET_ACCESS_KEY to enable S3 uploads.

Run the Application:

Bash
python3 gui.py
