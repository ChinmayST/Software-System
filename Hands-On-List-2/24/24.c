/*
============================================================================
Name : 24.c
Author : Chinmay Tavarej
Description : Write a program to create a message queue and print the key and message queue id.
Date: 10th Oct , 2024
============================================================================
*/

#include <sys/types.h> // Import for `ftok` & `msgget`
#include <sys/ipc.h>   // Import for `ftok` & `msgget`
#include <sys/msg.h>   // Import for `msgget`
#include <stdio.h>     // Import for `perror` & `printf`
#include <unistd.h>    // Import for `_exit`
#include <errno.h>     // Import for `errno`

void main()
{
    key_t queueKey;      // IPC (Message Queue) key
    int queueIdentifier; // IPC (Message Queue) identifier

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | IPC_EXCL | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n", queueIdentifier);
}
/*
============================================================================
Output :  XXXXX
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/24$ gcc 24.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/24$ ./a.out
Key: 17324734
Message Queue Identifier: 0
============================================================================
*/ 
