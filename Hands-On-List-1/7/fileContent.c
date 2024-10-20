/*
====================================================================================================================================================================================
Name : 7.c
Author : Chinmay Tavarej
Description :
Write a program to copy file1 into file2 ($cp file1 file2).

===================================================================================================================================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    char sourceFile[30];
    char targetFile[30];
    int character;


    printf("Please specify the source file name: ");
    if (scanf("%29s", sourceFile) != 1) {
        fprintf(stderr, "Failed to read source file name.\n");
        return EXIT_FAILURE;
    }

  
    inputFile = fopen(sourceFile, "r");
    if (inputFile == NULL) {
        perror("Error opening source file");
        return EXIT_FAILURE;
    }

    
    printf("Please specify the destination file name: ");
    if (scanf("%29s", targetFile) != 1) {
        fprintf(stderr, "Failed to read destination file name.\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }
    
    outputFile = fopen(targetFile, "w");
    if (outputFile == NULL) {
        perror("Error opening destination file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Copy contents from source file to destination file
    while ((character = fgetc(inputFile)) != EOF) {
        fputc(character, outputFile);
    }

    // Notify user that the content was successfully copied
    printf("Content successfully copied to '%s'.\n", targetFile);

    // Close both files
    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}
/*
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/7$ ./a.out
Please specify the source file name: test1.txt
Please specify the destination file name: text2.txt
Content successfully copied to 'text2.txt'.
/*

