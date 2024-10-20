/*
============================================================================
Name : 8a.c
Author : Chinmay Tavarej
Description : Write a separate program using signal system call to catch `SIGSEGV`
Date: 10th Oct , 2024
============================================================================
*/


#include <signal.h> // Import for `signal`, `raise`
#include <stdio.h>  // Import for `printf`, `scanf` & `perror`
#include <unistd.h> // Import for `_exit`

void callback()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    signalStatus = signal(SIGSEGV, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGSEGV); // Send segmentation fault signal
        
}

/*
============================================================================
Output : 

iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/8$ gcc 8a.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/8$ ./a.out
Signal SIGSEGV has been caught!

============================================================================
*/ 
