/*
====================================================================================================================================================================================
Name : main.c
Author : Chinmay Tavarej
Description :Write a program to create a Zombie state of the running program.

Date : 25th August 2024
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    
    child_pid = fork();

    if (child_pid < 0) {
        fprintf(stderr, "Error: Failed to create child process.\n");
        return EXIT_FAILURE;
    }

    if (child_pid == 0) {
        
        printf("The child process is terminating now.\n");
        _exit(EXIT_SUCCESS);  
    } else {

        printf("Parent process is creating a child.\n");
        printf("Parent will sleep for 10 seconds...\n");
        sleep(10);

        printf("Parent is about to wait for child process.\n");
        wait(NULL);

        printf("Parent process has reaped the zombie process.\n");
    }

    return EXIT_SUCCESS;
}



/*
output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/23$ gcc main.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/23$ ./a.out
Parent process is creating a child.
Parent will sleep for 10 seconds...
The child process is terminating now.
Parent is about to wait for child process.
Parent process has reaped the zombie process.

*/

