/*
============================================================================
Name : 14.c
Author : Chinmay Tavarej
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 10th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void display_file_category(mode_t fileMode) {
    if (S_ISREG(fileMode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(fileMode)) {
        printf("Directory\n");
    } else if (S_ISLNK(fileMode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(fileMode)) {
        printf("Character device\n");
    } else if (S_ISBLK(fileMode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(fileMode)) {
        printf("FIFO (named pipe)\n");
    } else if (S_ISSOCK(fileMode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *pathToFile = argv[1];
    struct stat fileInfo;

    if (stat(pathToFile, &fileInfo) == -1) {
        perror("Error retrieving file information");
        exit(EXIT_FAILURE);
    }

    display_file_category(fileInfo.st_mode);

    return 0;
}

/*
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab14$ ./a.out test.txt
Text file/Regular file

*/

