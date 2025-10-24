#!/bin/bash

echo "Choose your method of operation:"
echo "1. Shell Scripting"
echo "2. C System Calls"
read method

case $method in
    1)
        bash file_tool.sh
        ;;
    2)
        gcc -o file_manager file_tool.c && ./file_manager
        ;;
    *)
        echo "Invalid choice. Exiting."
        exit 1
        ;;
esac
