/*
====================================================================================================================================================================================
Name : 28.c
Author : Chinmay Tavarej
Description :
Write a program to get maximum and minimum real time priority.

Date : 27th August 2024
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main() {
    int max_priority, min_priority;


    max_priority = sched_get_priority_max(SCHED_FIFO);
    if (max_priority == -1) {
        perror("Error obtaining maximum priority");
        exit(EXIT_FAILURE);
    }


    min_priority = sched_get_priority_min(SCHED_FIFO);
    if (min_priority == -1) {
        perror("Error obtaining minimum priority");
        exit(EXIT_FAILURE);
    }


    printf("Maximum priority: %d\n", max_priority);
    printf("Minimum priority: %d\n", min_priority);

    return EXIT_SUCCESS;
}

/*
output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab28$ gcc 28.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab28$ ./a.out
Max. priority: 99
Min. priority: 1
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab28$ 


*/
