/*
============================================================================
Name : 15.c
Author : Chinmay Tavarej
Description : Write a simple program to send some data from parent to the child process.
Date: 10th Oct , 2024
============================================================================
*/

#include <unistd.h>    // Import for `pipe`, `write`, `read` & `fork` system calls
#include <sys/types.h> // Import for `fork`
#include <stdio.h>     // Import for `printf` and `perror`

void main()
{
    pid_t childPid;
    // File descriptor used for pipe operations
    int pipefd[2];             // pipefd[0] -> read, pipefd[1] -> write
    int pipeStatus;            // Variable used to determine success of `pipe` call
    int readBytes, writeBytes; // Number of bytes written using `write` & read using `read`

    char *writeBuffer = "Hello child! It's Dad!", *readBuffer;

    pipeStatus = pipe(pipefd);

    if (pipeStatus == -1)
        perror("Error while creating pipe!");
    else
    {
        printf("Pipe created successfully\n");
        childPid = fork();
        if (childPid == -1)
            perror("Error whiling forking new child!");
        else if (childPid == 0)
        {
            // Child enters this branch
            readBytes = read(pipefd[0], &readBuffer, sizeof(writeBuffer));
            if (readBytes == -1)
                perror("Error while reading from pipe!\n");
            else
                printf("Data from parent: %s\n", readBuffer);
        }
        else
        {
            // Parent enters this branch
            writeBytes = write(pipefd[1], &writeBuffer, sizeof(writeBuffer));
            if (writeBytes == -1)
                perror("Error while writing to pipe!");
        }
    }
}

/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/15$ gcc 15.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/15$ ./a.out
Pipe created successfully
Data from parent: Hello child! It's Dad!


============================================================================
*/ 
