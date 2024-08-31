s/*
====================================================================================================================================================================================
Name : 26.c
Author : Chinmay Tavarej
Description :Write a program to create an orphan process.

Date : 28th August 2024
===================================================================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *executable = "./a.out";
    char *args[] = {executable, "Chinmay", NULL};

    if (execvp(executable, args) == -1) {
        perror("Failed to execute");
        exit(1);
    }

    printf("Successful, so passed control to executable\n");

    return 0;
}

/*
output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/26 no$ ./a.out Chinmay
Hello, Chinmay!
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/26 no$ 


*/

