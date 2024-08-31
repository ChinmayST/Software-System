/*
============================================================================
Name : 12.c
Author : Chinmay Tavarej
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 10th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void display_file_mode(int fileDescriptor) {
    int fileFlags = fcntl(fileDescriptor, F_GETFL);
    if (fileFlags == -1) {
        perror("fcntl error");
        exit(EXIT_FAILURE);
    }

    int mode = fileFlags & O_ACCMODE;
    switch (mode) {
        case O_RDONLY:
            printf("The file is opened in read-only mode.\n");
            break;
        case O_WRONLY:
            printf("The file is opened in write-only mode.\n");
            break;
        case O_RDWR:
            printf("The file is opened in read-write mode.\n");
            break;
        default:
            printf("The file opening mode is unknown.\n");
            break;
    }

    if (fileFlags & O_APPEND) {
        printf("The file is opened with append mode.\n");
    }
    if (fileFlags & O_NONBLOCK) {
        printf("The file is opened in non-blocking mode.\n");
    }
    if (fileFlags & O_SYNC) {
        printf("The file is opened with synchronous I/O mode.\n");
    }
    if (fileFlags & O_CREAT) {
        printf("The file is opened with the O_CREAT flag.\n");
    }
    if (fileFlags & O_TRUNC) {
        printf("The file is opened with the O_TRUNC flag.\n");
    }
    if (fileFlags & O_EXCL) {
        printf("The file is opened with the O_EXCL flag.\n");
    }
}

int main() {
    const char *fileName = "example_file.txt";

    int fileDescriptor = open(fileName, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fileDescriptor == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    display_file_mode(fileDescriptor);

    close(fileDescriptor);

    return 0;
}


/*
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab12$ ./a.out
File is opened in read-write mode.
File is opened in append mode.

*/
