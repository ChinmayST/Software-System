/*
============================================================================
Name : 12.c
Author : Chinmay Tavarej
Description : Write a program to create an orphan process. Use `kill` system call to send `SIGKILL` signal to the parent process from the child process.
Date: 10th Oct , 2024
============================================================================
*/


#include <sys/types.h> // Import for `kill`, `fork`
#include <signal.h>    // Import for `kill`
#include <unistd.h>    // Import for `fork`, `sleep`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    pid_t childPid, parentPid;
    int killStatus; // Determines success of `kill`

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (!childPid)
    {
        // Child will enter this branch
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        killStatus = kill(getppid(), SIGKILL);

        if (!killStatus)
        {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        }
        else
            perror("Error while killing parent!");
    }
    else
    {
        // Parent will enter this branch
        while (1);
    }
}

/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/12$ gcc 12.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/12$ ./a.out
Child PID: 20323
Parent PID: 20322

============================================================================
*/ 
