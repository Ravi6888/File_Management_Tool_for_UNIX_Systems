#!/bin/bash

# File Management Tool for UNIX Systems

# Function to display the menu
show_menu() {
    echo "========== UNIX File Management Tool =========="
    echo "1. Create a file"
    echo "2. Delete a file"
    echo "3. Read a file"
    echo "4. Write to a file"
    echo "5. List files in a directory"
    echo "6. Change directory"
    echo "7. Show file permissions"
    echo "8. Search for a file"
    echo "9. Compress/Decompress a file"
    echo "10. Exit"
    echo "==============================================="
}

# Function to create a file
create_file() {
    echo -n "Enter the filename to create: "
    read filename
    if [ -e "$filename" ]; then
        echo "File already exists."
    else
        touch "$filename"
        echo "File '$filename' created successfully."
    fi
}

# Function to delete a file
delete_file() {
    echo -n "Enter the filename to delete: "
    read filename
    if [ -e "$filename" ]; then
        rm "$filename"
        echo "File '$filename' deleted successfully."
    else
        echo "File does not exist."
    fi
}

# Function to read a file
read_file() {
    echo -n "Enter the filename to read: "
    read filename
    if [ -r "$filename" ]; then
        cat "$filename"
    else
        echo "File does not exist or is not readable."
    fi
}

# Function to write to a file
write_file() {
    echo -n "Enter the filename to write to: "
    read filename
    if [ -e "$filename" ]; then
        echo "Enter the content to write (Press Ctrl+D to save):"
        cat >> "$filename"
        echo "Content written to '$filename'."
    else
        echo "File does not exist. Do you want to create it? (y/n): "
        read choice
        if [ "$choice" == "y" ]; then
            touch "$filename"
            echo "File created. Enter the content (Press Ctrl+D to save):"
            cat >> "$filename"
            echo "Content written to '$filename'."
        else
            echo "Operation canceled."
        fi
    fi
}

# Function to list files in a directory
list_files() {
    echo -n "Enter the directory path: "
    read dir
    if [ -d "$dir" ]; then
        ls -lh "$dir"
    else
        echo "Directory does not exist."
    fi
}

# Function to change directory
change_directory() {
    echo -n "Enter the directory path: "
    read dir
    if [ -d "$dir" ]; then
        cd "$dir" || exit
        echo "Current directory: $(pwd)"
    else
        echo "Directory does not exist."
    fi
}

# Function to show file permissions
show_permissions() {
    echo -n "Enter the filename: "
    read filename
    if [ -e "$filename" ]; then
        ls -l "$filename"
    else
        echo "File does not exist."
    fi
}

# Function to search for a file
search_file() {
    echo -n "Enter the filename to search for: "
    read filename
    echo -n "Enter the directory to search in (leave blank for current directory): "
    read dir
    if [ -z "$dir" ]; then
        dir="."
    fi
    find "$dir" -name "$filename"
}

# Function to compress or decompress a file
compress_decompress_file() {
    echo "1. Compress a file"
    echo "2. Decompress a file"
    echo -n "Choose an option: "
    read option
    case $option in
        1)
            echo -n "Enter the filename to compress: "
            read filename
            if [ -e "$filename" ]; then
                gzip "$filename"
                echo "File compressed to '$filename.gz'."
            else
                echo "File does not exist."
            fi
            ;;
        2)
            echo -n "Enter the filename to decompress: "
            read filename
            if [ -e "$filename" ]; then
                gunzip "$filename"
                echo "File decompressed."
            else
                echo "File does not exist."
            fi
            ;;
        *)
            echo "Invalid option."
            ;;
    esac
}

# Main script loop
while true; do
    show_menu
    echo -n "Enter your choice: "
    read choice
    case $choice in
        1) create_file ;;
        2) delete_file ;;
        3) read_file ;;
        4) write_file ;;
        5) list_files ;;
        6) change_directory ;;
        7) show_permissions ;;
        8) search_file ;;
        9) compress_decompress_file ;;
        10) echo "Exiting..."; exit ;;
        *) echo "Invalid choice. Please try again." ;;
    esac
    echo
done