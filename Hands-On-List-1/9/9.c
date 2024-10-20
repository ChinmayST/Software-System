/*
============================================================================
Name : 9.c
Author : Chinmay Tavarej
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void displayFileDetails(const char *path) {
    struct stat file_info;

    if (stat(path, &file_info) == -1) {
        perror("stat error");
        return;
    }

    printf("a. Inode number: %lu\n", file_info.st_ino);
    printf("b. Number of hard links: %lu\n", file_info.st_nlink);
    printf("c. User ID (UID): %u\n", file_info.st_uid);
    printf("d. Group ID (GID): %u\n", file_info.st_gid);
    printf("e. Size: %ld bytes\n", file_info.st_size);
    printf("f. Block size: %ld bytes\n", file_info.st_blksize);
    printf("g. Number of blocks: %ld\n", file_info.st_blocks);
    printf("h. Last access time: %s\n", ctime(&file_info.st_atime));
    printf("i. Last modification time: %s\n", ctime(&file_info.st_mtime));
    printf("j. Last status change time: %s\n", ctime(&file_info.st_ctime));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    displayFileDetails(argv[1]);

    return 0;
}

/*
Input:/a.out test.txt
Output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab9$ ./a.out test.txt
a. Inode number: 3423564
b. Number of hard links: 1
c. User ID (UID): 1000
d. Group ID (GID): 1000
e. Size: 24 bytes
f. Block size: 4096 bytes
g. Number of blocks: 8
h. Last access time: Sat Aug 13 15:49:51 2024

i. Last modification time: Fri Aug 11 00:32:14 2024

j. Last status change time: Sat Aug 11 15:19:05 2024



*/

