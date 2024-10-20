/*
============================================================================
Name : 28.c
Author : Chinmay Tavarej
Description : Write a program to change the exiting message queue permission. (Use `msqid_ds` structure)
Date: 10th Oct , 2024
============================================================================
*/

#include <sys/types.h> // Import for `ftok` `msgget` & `msgctl`
#include <sys/ipc.h>   // Import for `ftok` `msgget` & `msgctl`
#include <sys/msg.h>   // Import for `msgget` & `msgctl`
#include <stdio.h>     // Import for `perror` & `printf`
#include <unistd.h>    // Import for `_exit`

void main()
{
    key_t queueKey;                   // IPC (Message Queue) key
    int queueIdentifier;              // IPC (Message Queue) identifier
    struct msqid_ds messageQueueInfo; // IPC (Message Queue) information
    int msgctlStatus;                 // Determines success of `msgctl` call

    queueKey = ftok(".", 1);

    if (queueKey == -1)
    {
        perror("Error while computing key!");
        _exit(0);
    }

    queueIdentifier = msgget(queueKey, IPC_CREAT | 0700);
    if (queueIdentifier == -1)
    {
        perror("Error while creating Message Queue!");
        _exit(0);
    }

    printf("Key: %d\n", queueKey);
    printf("Message Queue Identifier: %d\n\n", queueIdentifier);

    msgctlStatus = msgctl(queueIdentifier, IPC_STAT, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while getting Message Queue info!");
        _exit(0);
    }

    printf("Press enter to change the permissions!\n");
    getchar();

    messageQueueInfo.msg_perm.mode = 0777;

    msgctlStatus = msgctl(queueIdentifier, IPC_SET, &messageQueueInfo);

    if (msgctlStatus == -1)
    {
        perror("Error while changing Message Queue permission!");
        _exit(0);
    }
}
/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/28$ gcc 28.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/28$ ./a.out
Key: 17324776
Message Queue Identifier: 4



============================================================================
*/ 
