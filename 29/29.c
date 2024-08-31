/*
====================================================================================================================================================================================
Name : 29.c
Author : Chinmay Tavarej
Description :
Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

void showPolicy(int sched_policy) {
    switch (sched_policy) {
        case SCHED_FIFO:
            printf("Current Scheduling Policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current Scheduling Policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current Scheduling Policy: SCHED_OTHER (Default)\n");
            break;
        default:
            printf("Unknown Scheduling Policy\n");
    }
}

int main(int argc, char *argv[]) {
    pid_t current_pid;
    int current_policy;
    struct sched_param sched_params;

    current_pid = getpid();

    current_policy = sched_getscheduler(current_pid);
    if (current_policy == -1) {
        perror("Failed to retrieve scheduler policy");
        exit(EXIT_FAILURE);
    }

    showPolicy(current_policy);

    sched_params.sched_priority = sched_get_priority_max(SCHED_FIFO);
    if (sched_setscheduler(current_pid, SCHED_FIFO, &sched_params) == -1) {
        perror("Failed to set SCHED_FIFO policy");
        exit(EXIT_FAILURE);
    }

    printf("Scheduler policy set to SCHED_FIFO.\n");

    current_policy = sched_getscheduler(current_pid);
    if (current_policy == -1) {
        perror("Failed to retrieve scheduler policy");
        exit(EXIT_FAILURE);
    }

    showPolicy(current_policy);

    sched_params.sched_priority = sched_get_priority_max(SCHED_RR);
    if (sched_setscheduler(current_pid, SCHED_RR, &sched_params) == -1) {
        perror("Failed to set SCHED_RR policy");
        exit(EXIT_FAILURE);
    }

    printf("Scheduler policy set to SCHED_RR.\n");

    current_policy = sched_getscheduler(current_pid);
    if (current_policy == -1) {
        perror("Failed to retrieve scheduler policy");
        exit(EXIT_FAILURE);
    }

    showPolicy(current_policy);

    return EXIT_SUCCESS;
}


/*
output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/29 no$ ./a.out
Current Scheduling Policy: SCHED_OTHER (Default)
Failed to set SCHED_FIFO policy: Operation not permitted
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/29 no$ sudo ./a.out fifo
Current Scheduling Policy: SCHED_OTHER (Default)
Scheduler policy set to SCHED_FIFO.
Current Scheduling Policy: SCHED_FIFO
Scheduler policy set to SCHED_RR.
Current Scheduling Policy: SCHED_RR

Current Scheduling Policy: SCHED_FIFO
Scheduling policy changed to SCHED_RR.
Current Scheduling Policy: SCHED_RR
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab29$ 

*/

