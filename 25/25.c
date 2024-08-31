/*
====================================================================================================================================================================================
Name : 25.c
Author : Chinmay Tavarej
Description :Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).

Date : 25th August 2024
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pids[3]; 


    for (int index = 0; index < 3; index++) {
        child_pids[index] = fork();

        if (child_pids[index] < 0) {
            perror("fork error");
            exit(EXIT_FAILURE);
        } else if (child_pids[index] == 0) {
            printf("Child %d with PID %d\n", index + 1, getpid());
            sleep(2);   
            exit(EXIT_SUCCESS);
        }
    }

    int child_status;
    pid_t specific_pid = child_pids[1]; 

    printf("Waiting for child process with PID %d\n", specific_pid);
    pid_t returned_pid = waitpid(specific_pid, &child_status, 0);

    if (returned_pid == -1) {
        perror("waitpid error");
        exit(EXIT_FAILURE);
    } else {
        printf("Child process with PID %d terminated with status %d\n", returned_pid, WEXITSTATUS(child_status));
    }

    return EXIT_SUCCESS;
}

/*
output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab25$ ./a.out
Child 1 with PID 10469
Waiting for child process with PID 10470
Child 2 with PID 10470
Child 3 with PID 10471
Child process with PID 10470 terminated with status 0


*/

