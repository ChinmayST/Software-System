/*
====================================================================================================================================================================================
Name : 22.c
Author : Chinmay Tavarej
Description :
Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

Date : 25th August 2024
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int file_descriptor;
    pid_t child_pid;

    // Open file for writing, create if not exists, and truncate it
    file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_descriptor < 0) {
        perror("Error opening file");
        return 1;
    }

    // Create a new process
    child_pid = fork();

    if (child_pid < 0) {
        perror("Error creating child process");
        return 1;
    }

    if (child_pid == 0) {
        // Code executed by the child process
        const char child_msg[] = "Child process writes to the file.\n";
        write(file_descriptor, child_msg, sizeof(child_msg) - 1);
    } else {
        // Code executed by the parent process
        const char parent_msg[] = "Parent process writes to the file.\n";
        write(file_descriptor, parent_msg, sizeof(parent_msg) - 1);
    }

    // Close the file descriptor
    close(file_descriptor);

    return 0;
}


/*
output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab22$ gcc 22.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab22$ ./a.out
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab22$ cat out.txt
Parent process writes to the file.
Child process writes to the file.


*/

