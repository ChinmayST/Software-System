/*
====================================================================================================================================================================================
Name : 20.c
Author : Chinmay Tavarej
Description :
Find out the priority of your running program. Modify the priority with nice command

Date : 25th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    pid_t pid = getpid(); 
    int initial_prio = getpriority(PRIO_PROCESS, pid); 
    printf("Initial priority: %d\n", initial_prio);

    int change_amount = 5; 
    int status = nice(change_amount); 

    if (status == -1) {
        perror("Failed to adjust priority"); 
    } else {
        int new_prio = getpriority(PRIO_PROCESS, pid); 
        printf("New priority: %d\n", new_prio);
    }

    return 0;
}


/*
output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab20$ gcc 20.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab20$ ./a.out
Initial priority: 0
New priority: 5

*/
