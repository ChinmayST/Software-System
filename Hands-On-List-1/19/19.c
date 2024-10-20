/*
====================================================================================================================================================================================
Name : 19.c
Author : Chinmay Tavarej
Description :
Write a program to find out time taken to execute getpid system call. Use time stamp counter.

Date : 25th August 2024
===================================================================================================================================================================================
*/

#include <stdio.h>
#include <unistd.h>

static inline unsigned long long read_time_stamp_counter() {
    unsigned int low, high;
    asm volatile ("rdtsc" : "=a" (low), "=d" (high));
    return ((unsigned long long)high << 32) | low;
}

int main() {
    unsigned long long start_time, end_time;
    pid_t process_id;

    start_time = read_time_stamp_counter();

    process_id = getpid();

    end_time = read_time_stamp_counter();

    printf("Elapsed time: getpid() execution took %llu CPU cycles\n", end_time - start_time);

    return 0;
}


/*

output:
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/19$ ./a.out
ELapsed Time: getpid() execution took 14352 CPU cycles
iiitb@iiitb-Dell-G15-5511:~/Downloads/Software System/19$ 

*/



