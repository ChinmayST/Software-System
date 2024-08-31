/*
====================================================================================================================================================================================
Name : 16.c
Author : Chinmay Tavarej
Description :
Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock

Date : 28th August 2024
===================================================================================================================================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>

int main()
{
    int file_descriptor = open("test.txt", O_WRONLY | O_APPEND);
    if (file_descriptor == -1)
    {
        printf("Unable to open file \n");
        exit(0);
    }

    struct flock file_lock;
    file_lock.l_type = F_WRLCK;
    file_lock.l_whence = SEEK_SET;
    file_lock.l_start = 0;
    file_lock.l_len = 0;
  
    int lock_status = fcntl(file_descriptor, F_SETLK, &file_lock);
    if (lock_status == -1)
    {
        printf("Unable to acquire write lock, exiting program \n");
        exit(0);
    }

    char *message = "This is written while locking the file \n";
    write(file_descriptor, message, 37);

    file_lock.l_type = F_UNLCK;
    fcntl(file_descriptor, F_SETLK, &file_lock);

    close(file_descriptor);

    file_descriptor = open("test.txt", O_RDONLY);
    file_lock.l_type = F_RDLCK;

    lock_status = fcntl(file_descriptor, F_SETLK, &file_lock);
    if (lock_status == -1)
    {
        printf("Unable to acquire read lock, exiting program \n");
        exit(0);
    }

    char buffer[1024];
    ssize_t bytes_read;
  
    while ((bytes_read = read(file_descriptor, buffer, 1)) > 0)
    {
        printf("%s", buffer);
    }

    file_lock.l_type = F_UNLCK;
    fcntl(file_descriptor, F_SETLK, &file_lock);

    close(file_descriptor);
}



/*
====================================================================================================================================================================================
Output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/16$ ./a.out
This is written while locking the file

====================================================================================================================================================================================
*/
