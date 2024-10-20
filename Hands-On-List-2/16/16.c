/*
============================================================================
Name : 16.c
Author : Chinmay Tavarej
Description : Write a program to send and receive data from parent to child vice versa. Use two way communication.
Date: 10th Oct , 2024
============================================================================
*/

#include <unistd.h>    // Import for `pipe`, `write`, `read` & `fork` system calls
#include <sys/types.h> // Import for `fork`
#include <stdio.h>     // Import for `printf` and `perror`
#include <stdlib.h>    // Import for `exit`

int main() {
    // File descriptors for pipe operations
    int childToParentfd[2], parentToChildfd[2];
    int childToParentPipeStatus;
    int parentToChildPipeStatus;
    ssize_t readBytes, writeBytes; // Use ssize_t for `write` and `read`
    char writeBuffer[100]; // Buffer for writing data
    char readBuffer[100];  // Buffer for reading data

    pid_t childPid;

    // Create pipes
    childToParentPipeStatus = pipe(childToParentfd);
    parentToChildPipeStatus = pipe(parentToChildfd);

    if (childToParentPipeStatus == -1 || parentToChildPipeStatus == -1) {
        perror("Error while creating the pipe!");
        exit(1);
    }

    childPid = fork();

    if (childPid == -1) {
        perror("Error while forking child!");
        exit(1);
    } else if (childPid == 0) {
        // Child process
        close(parentToChildfd[1]); // Close the write fd for parent-to-child pipe
        close(childToParentfd[0]); // Close the read fd for child-to-parent pipe

        // Sending data to parent
        snprintf(writeBuffer, sizeof(writeBuffer), "Hi mom! It's me!");
        writeBytes = write(childToParentfd[1], writeBuffer, sizeof(writeBuffer));
        if (writeBytes == -1) {
            perror("Error while writing to child to parent pipe!");
            exit(1);
        }

        // Reading from parent
        readBytes = read(parentToChildfd[0], readBuffer, sizeof(readBuffer));
        if (readBytes == -1) {
            perror("Error while reading from parent to child pipe!");
            exit(1);
        } else {
            readBuffer[readBytes] = '\0'; // Null-terminate the string
            printf("The parent said: %s\n", readBuffer);
        }
    } else {
        // Parent process
        close(parentToChildfd[0]); // Close the read fd for parent-to-child pipe
        close(childToParentfd[1]); // Close the write fd for child-to-parent pipe

        // Sending data to child
        snprintf(writeBuffer, sizeof(writeBuffer), "Hi child! It's me, mom!");
        writeBytes = write(parentToChildfd[1], writeBuffer, sizeof(writeBuffer));
        if (writeBytes == -1) {
            perror("Error while writing to parent to child pipe!");
            exit(1);
        }

        // Reading from child
        readBytes = read(childToParentfd[0], readBuffer, sizeof(readBuffer));
        if (readBytes == -1) {
            perror("Error while reading from child to parent pipe!");
            exit(1);
        } else {
            readBuffer[readBytes] = '\0'; // Null-terminate the string
            printf("The child said: %s\n", readBuffer);
        }
    }

    return 0;
}

/*
============================================================================
Output : 
The parent said: Hi child! It's me, mom!
The child said: Hi mom! It's me!
============================================================================
*/ 
