/*
============================================================================
Name : 32d.c
Author : Chinmay Tavarej
Description : Write a program to implement semaphore to protect any critical section - remove the created semaphore
Date: 10th Oct , 2024
============================================================================
*/


#include <sys/types.h> // Import for `ftok`, `semget`, `semctl`
#include <sys/ipc.h>   // Import for `ftok`, `semget`, `semctl`
#include <sys/sem.h>   // Import for `semget`, `semctl`
#include <unistd.h>    // Import for `_exit`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    key_t semKey;
    int semIndentifier;
    int semctlStatus;

    semKey = ftok(".", 1);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semIndentifier = semget(semKey, 1, IPC_CREAT | 0777);

    if (semIndentifier == -1)
    {
        perror("Error while creating semaphore!");
        _exit(1);
    }

    printf("Press enter to delete the semaphore!\n");
    getchar();

    semctlStatus = semctl(semIndentifier, 0, IPC_RMID);

    if (semctlStatus == -1)
    {
        perror("Error while deleting semaphore!");
        _exit(0);
    }
}

/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/32$ gcc 32d.c -o 32d
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/32$ ./32d
Press enter to delete the semaphore!



============================================================================
*/ 
