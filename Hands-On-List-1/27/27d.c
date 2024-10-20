/*
====================================================================================================================================================================================
Name : 27d.c
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
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-Rl", NULL};
    
    execv("/bin/ls", args);

    perror("execv failed");
    return 1;
}
/*
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/27 no$ gcc 27d.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/27 no$ ./a.out
.:
total 312
-rw-rw-r-- 1 iiitb iiitb   1476 Aug 31 22:37  27a.c
-rw-rw-r-- 1 iiitb iiitb    685 Aug 31 22:38  27b.c
-rw-rw-r-- 1 iiitb iiitb   1281 Aug 31 22:39  27c.c
-rw-rw-r-- 1 iiitb iiitb   1450 Aug 30 00:32  27d.c
-rw-rw-r-- 1 iiitb iiitb   1517 Aug 30 00:32  27e.c
-rwxrwxr-x 1 iiitb iiitb  16056 Aug 31 22:39  a.out
-rw-rw-r-- 1 iiitb iiitb 282119 Aug 30 00:32 'Pasted image.png'



*/

