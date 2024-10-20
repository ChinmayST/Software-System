/*
============================================================================
Name : 10b.c
Author : Chinmay Tavarej
Description : Write a separate program using sigaction system call to catch `SIGINT` signal
Date: 10th Oct , 2024
============================================================================
*/


#include <signal.h> // Import for `sigaction`, `raise`
#include <stdio.h>  // Import for `perror` & `printf`
#include <unistd.h> // Import for `_exit`, `sleep`

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGINT (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGINT, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
        sleep(5);
}


