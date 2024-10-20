/*
============================================================================
Name : 11.c
Author : Chinmay Tavarej
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 10th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILE_PATH "test_file.txt"
#define BUF_SIZE 256

void display_file_contents() {
    char buf[BUF_SIZE];
    int file_descriptor = open(FILE_PATH, O_RDONLY);
    if (file_descriptor == -1) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    ssize_t read_bytes;
    printf("File contents:\n");
    while ((read_bytes = read(file_descriptor, buf, BUF_SIZE - 1)) > 0) {
        buf[read_bytes] = '\0';
        printf("%s", buf);
    }

    close(file_descriptor);
}

int main() {
    int orig_fd, dup_fd, dup2_fd, fcntl_fd;
    const char *msg1 = "Message written by original descriptor.\n";
    const char *msg2 = "Message written by dup descriptor.\n";
    const char *msg3 = "Message written by dup2 descriptor.\n";
    const char *msg4 = "Message written by fcntl descriptor.\n";

    orig_fd = open(FILE_PATH, O_WRONLY | O_APPEND | O_CREAT, 0644);
    if (orig_fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    dup_fd = dup(orig_fd);
    if (dup_fd == -1) {
        perror("Error duplicating file descriptor with dup");
        close(orig_fd);
        exit(EXIT_FAILURE);
    }

    dup2_fd = dup2(orig_fd, dup_fd + 1);
    if (dup2_fd == -1) {
        perror("Error duplicating file descriptor with dup2");
        close(orig_fd);
        close(dup_fd);
        exit(EXIT_FAILURE);
    }

    fcntl_fd = fcntl(orig_fd, F_DUPFD, dup2_fd + 1);
    if (fcntl_fd == -1) {
        perror("Error duplicating file descriptor with fcntl");
        close(orig_fd);
        close(dup_fd);
        close(dup2_fd);
        exit(EXIT_FAILURE);
    }

    if (write(orig_fd, msg1, strlen(msg1)) == -1) {
        perror("Error writing with original descriptor");
    }

    if (write(dup_fd, msg2, strlen(msg2)) == -1) {
        perror("Error writing with dup descriptor");
    }

    if (write(dup2_fd, msg3, strlen(msg3)) == -1) {
        perror("Error writing with dup2 descriptor");
    }

    if (write(fcntl_fd, msg4, strlen(msg4)) == -1) {
        perror("Error writing with fcntl descriptor");
    }

    close(orig_fd);
    close(dup_fd);
    close(dup2_fd);
    close(fcntl_fd);

    display_file_contents();

    return 0;
}


/*
Output: 
File content:
Text written by original descriptor.
Text written by dup descriptor.
Text written by dup2 descriptor.
Text written by fcntl descriptor.
Text written by original descriptor.
Text written by dup descriptor.
Text written by dup2 descriptor.
Text written by fcntl descriptor.
*/

