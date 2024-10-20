/*
============================================================================
Name : 17a.c
Author : Chinmay Tavarej
Description : Write a program to execute `ls -l | wc`. Use `dup`
Date: 10th Oct , 2024
============================================================================
*/

#include <unistd.h>    // Import for `pipe`, `fork`, `execl` & `dup`
#include <sys/types.h> // Import `fork`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    // File descriptor used for pipe operations
    int pipefd[2];  // pipefd[0] -> read, pipefd[1] -> write
    int pipeStatus; // // Variable used to determine success of `pipe` call
    pid_t childPid;

    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating the file!");
    else
    {
        childPid = fork();

        if (childPid == -1)
            perror("Error while forking child!");
        else if (childPid == 0)
        {
            // Child will enter this branch
            close(STDIN_FILENO);
            dup(pipefd[0]); // STDIN will be reassigned to pipefdp[0]
            close(pipefd[1]);
            execl("/usr/bin/wc", "wc", NULL);
        }
        else
        {
            // Parent will enter this branch
            close(STDOUT_FILENO);
            dup(pipefd[1]); // STDOUT will be reassigned to pipefd[1]
            close(pipefd[0]);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
    }
}
/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/17$ gcc 17a.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/17$ ./a.out
      5      38     209


============================================================================
*/ 
