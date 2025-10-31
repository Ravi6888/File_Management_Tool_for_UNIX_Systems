# File_Management_Tool_for_UNIX_systems

File Management Tool for UNIX Systems

A multi-language command-line tool that provides basic UNIX file management operations through Shell scripting and C system calls.

This project demonstrates how similar file operations can be implemented using both Bash and C, highlighting system-level and script-level approaches to managing files.

________________________________________

	**Features**

**Common Functionalities**

Both the Shell and C versions include:

•	Create and Delete Files

•	 Read and Write to Files

•	 List Files in a Directory

•	 Change Current Working Directory

•	 Show File Permissions

•	 Search for a File

•	 Compress/Decompress Files using gzip and gunzip

•	 Exit Menu Safely

**Multi-Language Support**

•	Option 1: Run via Shell Script (file_tool.sh)

•	Option 2: Run via C Program (file_tool.c) compiled and executed automatically by mfile_tool.sh

________________________________________

 **Project Structure**

File_Management_Tool_for_UNIX_Systems/

|── mfile_tool.sh  -----------------# Main launcher script (choose Shell or C method)

|── file_tool.sh   -----------------# Bash-based file management script

└── file_tool.c    -----------------# C-based file management program (system calls)

________________________________________

	**Requirements**

•	Operating System: Linux / UNIX / macOS

•	For Shell Version: Bash (default in most UNIX systems)

•	For C Version: GCC compiler

•	Utilities Used: gzip, gunzip, find, ls, cat, etc. (standard in UNIX systems)

________________________________________

	**How to Run the Project**

Step 1: Clone the Repository

  git clone https://github.com/Ravi6888/File_Management_Tool_for_UNIX_Systems.git

  cd File_Management_Tool_for_UNIX_Systems

Step 2: Make Scripts Executable

  chmod +x mfile_tool.sh file_tool.sh

Step 3: Run the Main Launcher

  ./mfile_tool.sh

Step 4: Choose Your Method

  You’ll be prompted:

Choose your method of operation:

1. Shell Scripting
2. C System Calls

Enter 1 to use the Bash version, or 2 to use the C version.

________________________________________

	**Example Usage**

**Shell Script Mode**

$ ./mfile_tool.sh

Choose your method of operation:

1. Shell Scripting
2. C System Calls

1

========== UNIX File Management Tool ==========

1. Create a file
2. Delete a file

...

Enter your choice: 1

Enter the filename to create: demo.txt

File 'demo.txt' created successfully.



**C Program Mode**

$ ./mfile_tool.sh

Choose your method of operation:

1. Shell Scripting
2. C System Calls

2

========== UNIX File Management Tool ==========

1. Create a file
2. Delete a file

...

Enter your choice: 5

Enter the directory path: .

file_tool.c

file_tool.sh

mfile_tool.sh

________________________________________

	**File Operations Overview**


<img width="954" height="309" alt="image" src="https://github.com/user-attachments/assets/49f879b6-cd1f-4d73-88b8-7677b2d26e91" />


________________________________________

	Customization Ideas

•	Add colorized output using ANSI codes.

•	Integrate logging of user operations.

•	Add input validation and error trapping.

•	Extend compression support (zip, tar).

•	Include a GUI front-end with zenity or Tkinter.
