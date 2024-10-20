/*
============================================================================
Name : 18.c
Author : Chinmay Tavarej
Description : Write a program to find out total number of directories on the `pwd`. Execute `ls -l | grep ^d | wc`. Use only `dup2`.
Date: 10th Oct , 2024
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int pipeCmdOneToTwo[2], pipeCmdTwoToThree[2];
    pid_t childOne, childTwo;

    if (pipe(pipeCmdOneToTwo) == -1 || pipe(pipeCmdTwoToThree) == -1) {
        perror("Error while creating the pipe!");
        exit(1);
    }

    childOne = fork();
    if (childOne == -1) {
        perror("Error while creating first child!");
        exit(1);
    } else if (childOne == 0) {
        // Child One - `wc`
        close(pipeCmdOneToTwo[1]); // Close write end of pipeOne
        close(pipeCmdTwoToThree[0]); // Close read end of pipeTwo

        dup2(pipeCmdOneToTwo[0], STDIN_FILENO); // Set stdin to read end of pipeOne
        close(pipeCmdOneToTwo[0]); // Close original read end

        execl("/usr/bin/wc", "wc", NULL);
        perror("execl failed");
        exit(1);
    } else {
        childTwo = fork();
        if (childTwo == -1) {
            perror("Error while creating second child!");
            exit(1);
        } else if (childTwo == 0) {
            // Child Two - `grep`
            close(pipeCmdOneToTwo[0]); // Close read end of pipeOne
            close(pipeCmdTwoToThree[0]); // Close read end of pipeTwo

            dup2(pipeCmdOneToTwo[1], STDOUT_FILENO); // Set stdout to write end of pipeOne
            close(pipeCmdOneToTwo[1]); // Close original write end

            dup2(pipeCmdTwoToThree[1], STDOUT_FILENO); // Set stdout to write end of pipeTwo
            close(pipeCmdTwoToThree[1]); // Close original write end

            execl("/usr/bin/grep", "grep", "^d", NULL);
            perror("execl failed");
            exit(1);
        } else {
            // Parent process - `ls -l`
            close(pipeCmdOneToTwo[0]); // Close read end of pipeOne
            close(pipeCmdTwoToThree[1]); // Close write end of pipeTwo

            dup2(pipeCmdOneToTwo[1], STDOUT_FILENO); // Set stdout to write end of pipeOne
            close(pipeCmdOneToTwo[1]); // Close original write end

            execl("/usr/bin/ls", "ls", "-l", NULL);
            perror("execl failed");
            exit(1);
        }
    }

    return 0;
}
/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/18$ gcc 18.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/18$ ./a.out
      3      20     108
============================================================================
*/ 
