<h1 align="center">File Management Tool for UNIX Systems</h1>

<p align="center">
  <b>A multi-language command-line tool for basic UNIX file operations using Shell scripting and C system calls.</b><br>
  Demonstrates system-level and script-level file management techniques side by side.
</p>

<hr>

<h2>➤ Project Overview</h2>
<p>
This project provides a <b>command-line file management tool</b> implemented in both <b>Bash</b> and <b>C</b>, showcasing how similar file operations can be handled through scripting and system calls.<br>
It offers basic file operations such as creation, deletion, reading, writing, searching, and compression — all within a UNIX-like environment.
</p>

<hr>

<h2>➤ Features</h2>

<h3>Common Functionalities</h3>
<p>Both the Shell and C versions include:</p>
<ul>
  <li> Create and Delete Files</li>
  <li> Read and Write to Files</li>
  <li> List Files in a Directory</li>
  <li> Change Current Working Directory</li>
  <li> Show File Permissions</li>
  <li> Search for a File</li>
  <li> Compress/Decompress Files using <code>gzip</code> and <code>gunzip</code></li>
  <li> Exit Menu Safely</li>
</ul>

<h3>Multi-Language Support</h3>
<ul>
  <li> <b>Option 1:</b> Run via Shell Script (<code>file_tool.sh</code>)</li>
  <li> <b>Option 2:</b> Run via C Program (<code>file_tool.c</code>) — compiled and executed automatically by <code>mfile_tool.sh</code></li>
</ul>

<hr>

<h2>➤ Project Structure</h2>
<pre>
File_Management_Tool_for_UNIX_Systems/
│
├── mfile_tool.sh      # Main launcher script (choose Shell or C method)
├── file_tool.sh       # Bash-based file management script
└── file_tool.c        # C-based file management program (system calls)
</pre>

<hr>

<h2>➤ Requirements</h2>
<ul>
  <li> <b>Operating System:</b> &nbsp;&nbsp; Linux / UNIX / macOS</li>
  <li> <b>For Shell Version:</b> &nbsp;&nbsp; Bash (default in most UNIX systems)</li>
  <li> <b>For C Version:</b> &nbsp;&nbsp; GCC compiler</li>
  <li> <b>Utilities Used:</b> &nbsp;&nbsp; gzip, gunzip, find, ls, cat, etc. (standard in UNIX systems)</li>
</ul>

<hr>

<h2>➤ How to Run the Project</h2>

<ol>
  <li><b>Step 1: Clone the Repository</b>
    <pre>
git clone https://github.com/Ravi6888/File_Management_Tool_for_UNIX_Systems.git
cd File_Management_Tool_for_UNIX_Systems
    </pre>
  </li>

  <li><b>Step 2: Make Scripts Executable</b>
    <pre>
chmod +x mfile_tool.sh file_tool.sh
    </pre>
  </li>

  <li><b>Step 3: Run the Main Launcher</b>
    <pre>
./mfile_tool.sh
    </pre>
  </li>

  <li><b>Step 4: Choose Your Method</b>
    <p>When prompted:</p>
    <pre>
Choose your method of operation:

1. Shell Scripting
2. C System Calls
    </pre>
    <p>Enter <b>1</b> to use the Bash version, or <b>2</b> to use the C version.</p>
  </li>
</ol>

<hr>

<h2>➤ Example Usage</h2>

<h3>Shell Script Mode</h3>
<pre>
$ ./mfile_tool.sh

Choose your method of operation:

1. Shell Scripting
2. C System Calls
1

========== UNIX File Management Tool ==========

Create a file
Delete a file
...

Enter your choice: 1
Enter the filename to create: demo.txt

File 'demo.txt' created successfully.
</pre>

<h3>C Program Mode</h3>
<pre>
$ ./mfile_tool.sh

Choose your method of operation:

1. Shell Scripting
2. C System Calls
2

========== UNIX File Management Tool ==========

Create a file
Delete a file
...

Enter your choice: 5
Enter the directory path: .

file_tool.c
file_tool.sh
mfile_tool.sh
</pre>

<hr>

<h2>➤ File Operations Overview</h2>

<table>
  <tr>
    <th>Operation</th>
    <th>Description</th>
    <th>Shell Command Used</th>
    <th>C System Call Used</th>
  </tr>
  <tr>
    <td>Create File</td>
    <td>Create a new file</td>
    <td><code>touch</code></td>
    <td><code>open()</code></td>
  </tr>
  <tr>
    <td>Delete File</td>
    <td>Remove a file</td>
    <td><code>rm</code></td>
    <td><code>unlink()</code></td>
  </tr>
  <tr>
    <td>Read File</td>
    <td>Display contents</td>
    <td><code>cat</code></td>
    <td><code>read()</code></td>
  </tr>
  <tr>
    <td>Write File</td>
    <td>Append or create new content</td>
    <td><code>cat &gt;&gt; file</code></td>
    <td><code>write()</code></td>
  </tr>
  <tr>
    <td>List Files</td>
    <td>Show directory contents</td>
    <td><code>ls</code></td>
    <td><code>readdir()</code></td>
  </tr>
  <tr>
    <td>Change Directory</td>
    <td>Move between directories</td>
    <td><code>cd</code></td>
    <td><code>chdir()</code></td>
  </tr>
  <tr>
    <td>Show Permissions</td>
    <td>Show file mode bits</td>
    <td><code>ls -l</code></td>
    <td><code>stat()</code></td>
  </tr>
  <tr>
    <td>Search File</td>
    <td>Find file by name</td>
    <td><code>find</code></td>
    <td><code>readdir()</code> loop</td>
  </tr>
  <tr>
    <td>Compress/Decompress</td>
    <td><code>gzip</code> / <code>gunzip</code></td>
    <td><code>gzip</code>, <code>gunzip</code></td>
    <td><code>execlp()</code></td>
  </tr>
</table>

<hr>

<h2>➤ Customization Ideas</h2>
<ul>
  <li> Add colorized output using ANSI escape codes for better readability.</li>
  <li> Integrate logging of user operations for debugging or audit purposes.</li>
  <li> Add input validation and error handling.</li>
  <li> Extend compression support to <code>zip</code> or <code>tar</code> formats.</li>
  <li> Include a GUI front-end using <code>zenity</code> or <code>Tkinter</code>.</li>
</ul>

<hr>


<hr>

<p align="center">
⭐ <i>If you found this project useful, consider giving it a star!</i> ⭐
</p>
