/*
============================================================================
Name : 1c.c
Author : Chinmay Tavarej
Description : Write a separate program (for each time domain) to set a interval timer in 10s and 10ms - `ITIMER_PROF`
Date: 10th Oct , 2024
============================================================================
*/

#include <sys/time.h> // Import `setitimer`
#include <signal.h>   // Import for `signal`
#include <unistd.h>   // Import for `pause`
#include <stdio.h>    // Import `perror` & `printf`

void main(int argc, char *argv[])
{
    int timerStatus; // Determines success of `setitimer` call

    struct itimerval timer;

    if (argc != 2)
    {
        printf("Pass 1 for 10s timer or 2 for 10ms timer\n");
        _exit(0);
    }

    if ((int)(*argv[1] - 48) == 1)
    {
        // Setting a interval timer for 10s
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    }
    else if ((int)(*argv[1] - 48) == 2)
    {
        // Setting a interval timer for 10ms
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
    }

    timerStatus = setitimer(ITIMER_PROF, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/1$ gcc 1c.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/1$ ./a.out
Pass 1 for 10s timer or 2 for 10ms timer

============================================================================
*/ 














































































    while(1);
}

/*
============================================================================

iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/1$ gcc 1c.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/1$ ./a.out
Pass 1 for 10s timer or 2 for 10ms timer
============================================================================
*/ 
