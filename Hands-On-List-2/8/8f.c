/*
============================================================================
Name : 8f.c
Author : Chinmay Tavarej
Description : Write a separate program using signal system call to catch `SIGVTALRM` (use `setitimer` system call)
Date: 10th Oct , 2024
============================================================================
*/


#include <sys/time.h> // Import `setitimer`
#include <signal.h>   // Import for `signal`
#include <unistd.h>   // Import for `_exit`
#include <stdio.h>    // Import `perror` & `printf`

void callback()
{
    printf("Signal SIGVTALRM has been caught!\n");
    _exit(0);
}

void main()
{
    int timerStatus;                  // Determines success of `setitimer` call
    __sighandler_t signalStatus; // Determines status of `signal` call

    struct itimerval timer;

    // Generate signal after 1s
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    timerStatus = setitimer(ITIMER_VIRTUAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    // Catch the SIGALRM signal
    signalStatus = signal(SIGVTALRM, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");
    else
        while (1);
}

/*
============================================================================
Output : 

iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/8$ gcc 8f.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/8$ ./a.out
Signal SIGVTALRM has been caught!

============================================================================
*/ 
