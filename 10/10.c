/*
============================================================================
Name : 10.c
Author : Chinmay Tavarej
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 10th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main() {
    int fileDescriptor;
    ssize_t writtenBytes;
    off_t currentOffset;


    fileDescriptor = open("text.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fileDescriptor == -1) {
        perror("Failed to open file");
        return 1;
    }


    writtenBytes = write(fileDescriptor, "I am Chinmay T.", 15);
    if (writtenBytes == -1) {
        perror("Failed to write to file");
        close(fileDescriptor);
        return 1;
    }


    currentOffset = lseek(fileDescriptor, 10, SEEK_CUR);
    if (currentOffset == -1) {
        perror("Failed to seek in file");
        close(fileDescriptor);
        return 1;
    } else {
        printf("Seek operation returned offset: %ld\n", currentOffset);
    }


    writtenBytes = write(fileDescriptor, "ABCDEFGHIJ", 10);
    if (writtenBytes == -1) {
        perror("Failed to write to file");
        close(fileDescriptor);
        return 1;
    }


    close(fileDescriptor);

    return 0;
}


/*
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/10$ ./a.out
Seek operation returned offset: 25
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/10$ od -c test.txt
0000000   T   H   I   S       I   S       T   E   M   P       F   I   L
0000020   E  \n
0000022
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/10$ 


*/

