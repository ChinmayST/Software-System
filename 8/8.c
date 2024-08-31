/*
============================================================================
Name : 8.c
Author : Chinmay Tavarej
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 10th Aug, 2024.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

const char LINE_END = '\n';

int main() {
    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch = fgetc(file);
    char tempBuffer[1024];
    int index = 0;

    while (ch != EOF) {
        while (ch != LINE_END && ch != EOF) {
            tempBuffer[index] = ch;
            index++;
            ch = fgetc(file);
        }

        tempBuffer[index++] = LINE_END;
        write(STDOUT_FILENO, tempBuffer, index);

        ch = fgetc(file);
        index = 0;
    }

    fclose(file);
    return EXIT_SUCCESS;
}
/*
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab8$ gcc 8.c
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab8$ ./a.out
This is a temp file to print
line by line
all the lines
abcdefg
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/lab8$ 

*/
