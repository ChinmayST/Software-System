/*
====================================================================================================================================================================================
Name : 21.c
Author : Chinmay Tavarej
Description :
Write a program, call fork and print the parent and child process id.

Date : 25th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main() {
    printf("Parent process PID: %d\n", getpid());

    int fork_result = fork();
    if (fork_result == 0) {
        // This block is executed by the child process
        printf("Child process PID: %d\n", getpid());
    } else if (fork_result > 0) {
        // This block is executed by the parent process
        printf("Parent process with child PID: %d and parent PID: %d\n", fork_result, getppid());
    } else {
        // This block handles the case where fork() fails
        perror("Failed to create child process");
    }

    return 0;
}

/*
Output:
Parent process PID: 19685
Parent process with child PID: 19686 and parent PID: 19669
Child process PID: 19686



*/
