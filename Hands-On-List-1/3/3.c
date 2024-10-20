/*
============================================================================
Name : 3.c
Author : Chinmay Tavarej
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 10th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main() {
    const char *filename = "testfile.txt";
    int fd;


    fd = open(filename, O_CREAT | O_WRONLY, 0644);


    if (fd == -1) {
        perror("Failed to create or open the file");
        return 1;
    }

    printf("File descriptor for '%s': %d\n", filename, fd);

    if (close(fd) == -1) {
        perror("Failed to close the file");
        return 1;
    }

    return 0;
}


/*
Input: ./file_descriptor
Output: File descriptor for 'testfile.txt' is 3
*/
