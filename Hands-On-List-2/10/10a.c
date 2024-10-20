/*
============================================================================
Name : 10a.c
Author : Chinmay Tavarej
Description : Write a separate program using sigaction system call to catch `SIGSEGV` signal
Date: 10th Oct , 2024
============================================================================
*/

#include <signal.h> // Import for `sigaction`, `raise`
#include <stdio.h>  // Import for `perror` & `printf`
#include <unistd.h> // Import for `_exit(0)`

void signalHandler(int signalNumber)
{
    printf("Caught signal SIGSEGV (%d)\n", signalNumber);
    _exit(0);
}

void main()
{
    int status; // Determines success of `sigaction` call
    struct sigaction action;
    char *a;

    action.sa_handler = signalHandler;
    action.sa_flags = 0;

    status = sigaction(SIGSEGV, &action, NULL);
    if (status == -1)
        perror("Error while setting signal handler!");
    else
    {
        raise(SIGSEGV);
    }
}

/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/10$ gcc 10a.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/10$ ./a.out
Caught signal SIGSEGV (11)


============================================================================
*/ 
