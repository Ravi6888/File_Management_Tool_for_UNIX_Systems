#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function prototypes
void create_file();
void delete_file();
void read_file();
void write_file();
void list_files();
void change_directory();
void show_permissions();
void search_file();
void compress_decompress_file();

void show_menu() {
    printf("========== UNIX File Management Tool ==========\n");
    printf("1. Create a file\n");
    printf("2. Delete a file\n");
    printf("3. Read a file\n");
    printf("4. Write to a file\n");
    printf("5. List files in a directory\n");
    printf("6. Change directory\n");
    printf("7. Show file permissions\n");
    printf("8. Search for a file\n");
    printf("9. Compress/Decompress a file\n");
    printf("10. Exit\n");
    printf("===============================================\n");
}

int main() {
    int choice;
    while (1) {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // Clear the input buffer
        switch (choice) {
            case 1: create_file(); break;
            case 2: delete_file(); break;
            case 3: read_file(); break;
            case 4: write_file(); break;
            case 5: list_files(); break;
            case 6: change_directory(); break;
            case 7: show_permissions(); break;
            case 8: search_file(); break;
            case 9: compress_decompress_file(); break;
            case 10: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
        printf("\n");
    }
    return 0;
}

void create_file() {
    char filename[256];
    printf("Enter the filename to create: ");
    scanf("%s", filename);

    int fd = open(filename, O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("Error creating file");
    } else {
        printf("File '%s' created successfully.\n", filename);
        close(fd);
    }
}

void delete_file() {
    char filename[256];
    printf("Enter the filename to delete: ");
    scanf("%s", filename);

    if (unlink(filename) < 0) {
        perror("Error deleting file");
    } else {
        printf("File '%s' deleted successfully.\n", filename);
    }
}

void read_file() {
    char filename[256];
    printf("Enter the filename to read: ");
    scanf("%s", filename);

    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    if (bytes_read < 0) {
        perror("Error reading file");
    }
    close(fd);
}

void write_file() {
    char filename[256];
    printf("Enter the filename to write to: ");
    scanf("%s", filename);

    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    printf("Enter the content to write (end with Ctrl+D):\n");
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        write(fd, buffer, strlen(buffer));
    }
    printf("Content written to '%s'.\n", filename);
    close(fd);
}

void list_files() {
    char dir_path[256];
    printf("Enter the directory path: ");
    scanf("%s", dir_path);

    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

void change_directory() {
    char dir_path[256];
    printf("Enter the directory path: ");
    scanf("%s", dir_path);

    if (chdir(dir_path) < 0) {
        perror("Error changing directory");
    } else {
        printf("Current directory: %s\n", getcwd(NULL, 0));
    }
}

void show_permissions() {
    char filename[256];
    printf("Enter the filename: ");
    scanf("%s", filename);

    struct stat file_stat;
    if (stat(filename, &file_stat) < 0) {
        perror("Error retrieving file information");
        return;
    }

    printf("Permissions: %o\n", file_stat.st_mode & 0777);
}

void search_file() {
    char filename[256], dir_path[256];
    printf("Enter the filename to search for: ");
    scanf("%s", filename);
    printf("Enter the directory to search in (leave blank for current directory): ");
    scanf("%s", dir_path);

    if (strlen(dir_path) == 0) {
        strcpy(dir_path, ".");
    }

    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, filename) == 0) {
            printf("File found: %s/%s\n", dir_path, filename);
        }
    }
    closedir(dir);
}

void compress_decompress_file() {
    printf("1. Compress a file\n");
    printf("2. Decompress a file\n");
    printf("Choose an option: ");
    int option;
    scanf("%d", &option);

    char filename[256];
    switch (option) {
        case 1:
            printf("Enter the filename to compress: ");
            scanf("%s", filename);
            if (execlp("gzip", "gzip", filename, NULL) < 0) {
                perror("Error compressing file");
            }
            break;
        case 2:
            printf("Enter the filename to decompress: ");
            scanf("%s", filename);
            if (execlp("gunzip", "gunzip", filename, NULL) < 0) {
                perror("Error decompressing file");
            }
            break;
        default:
            printf("Invalid option.\n");
    }
}
