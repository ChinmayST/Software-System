/*
============================================================================
Name : 7.c
Author : Chinmay Tavarej
Description : Write a simple program to print the created thread IDs.
Date: 10th Oct , 2024
============================================================================
*/
// Question : Write a simple program to print the created thread IDs.

#include <pthread.h> // Import for `pthread_create`
#include <stdio.h>   // Import for `perror` & `printf`

void sampleFunction()
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
}

void main()
{
    pthread_t threadID;

    // Create thread
    if(pthread_create(&threadID, NULL, (void *)sampleFunction, NULL))
        perror("Error while creating thread");

    pthread_exit(NULL);
}

/*
============================================================================
Output : 
Running in thread with thread ID: 140576198489792


============================================================================
*/ 
