/*
====================================================================================================================================================================================
Name : 24.c
Author : Chinmay Tavarej
Description :Write a program to create an orphan process.

Date : 25th August 2024
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_process_id;
    child_process_id = fork();

    if (child_process_id < 0) {
        perror("Fork error");
        return 1;
    }

    if (child_process_id == 0) {

        sleep(1);  
        printf("Child process (PID: %d) initially, Parent PID: %d\n", getpid(), getppid());

        sleep(10);  
        printf("Child process (PID: %d) after 10 seconds, Parent PID: %d\n", getpid(), getppid());
    } 
    else {

        printf("Parent process (PID: %d) is exiting.\n", getpid());
        exit(0);  
    }

    return 0;
}


/*
Output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab24$ gcc 24.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/24$ ./a.out
Parent process (PID: 10183) is exiting.
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/24$ Child process (PID: 10184) initially, Parent PID: 1757
Child process (PID: 10184) after 10 seconds, Parent PID: 1757



*/

