/*
============================================================================
Name : 8c.c
Author : Chinmay Tavarej
Description :  Write a separate program using signal system call to catch `SIGFPE` 
Date: 10th Oct , 2024
============================================================================
*/


#include <signal.h> // Import for `signal`, `raise`
#include <stdio.h>  // Import for `printf`, `scanf` & `perror`
#include <unistd.h> // Import for `_exit`

void callback()
{
    printf("Signal SIGFPE has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus; // Determines the success of the `signal` call

    signalStatus = signal(SIGFPE, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGFPE); // Send a signal associated with floating point error
}

/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/8$ gcc 8c.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/8$ ./a.out
Signal SIGFPE has been caught!


============================================================================
*/ 
