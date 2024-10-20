/*
====================================================================================================================================================================================
Name : 27a.c
Author : Chinmay Tavarej
Description :Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp

Date : 28th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
   printf("Output using execl system call.\n");
   if (execl("/bin/ls", "ls", "-Rl", NULL) == -1) {
       perror("execl failed");
     exit(1);
   }


    return 0;
}

/*

iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/27 no$ gcc 27a.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/27 no$ ./a.out
Output using execl system call.
.:
total 312
-rw-rw-r-- 1 iiitb iiitb   1387 Aug 30 00:32  27a.c
-rw-rw-r-- 1 iiitb iiitb    648 Aug 30 00:32  27b.c
-rw-rw-r-- 1 iiitb iiitb   1317 Aug 30 00:32  27c.c
-rw-rw-r-- 1 iiitb iiitb   1450 Aug 30 00:32  27d.c
-rw-rw-r-- 1 iiitb iiitb   1517 Aug 30 00:32  27e.c
-rwxrwxr-x 1 iiitb iiitb  16088 Aug 31 22:36  a.out
-rw-rw-r-- 1 iiitb iiitb 282119 Aug 30 00:32 'Pasted image.png'
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/27 no$ 

 

*/
