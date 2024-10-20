/*
============================================================================
Name : 4.c
Author : Chinmay Tavarej
Description : Write a program to measure how much time is taken to execute 100 `getppid()` system call. Use time stamp counter.
Date: 10th Oct , 2024
============================================================================
*/
  

#include <sys/time.h>  // Import for `gettimeofday` system call
#include <sys/types.h> // Import for `getpid` system call
#include <unistd.h>    // Import for `getpid` system call
#include <stdio.h>     // Import for printf

// Import for __rdtsc()
#ifdef _MSC_VER
#include <intrin.h>
#else
#include <x86intrin.h>
#endif

void main()
{
    int start, end, pid;
    struct timeval timestamp;
    int iter = 0;

    start = __rdtsc();
    while(iter < 100) {
        pid = getpid();
        iter++;
    }
    end = __rdtsc();

    printf("PID: %d\n", pid);
    printf("Time taken : %d ns \n",  (int) ((end - start)/2.4));
}

/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/4$ gcc 4.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/4$ ./a.out
PID: 16926
Time taken : 31935 ns 
iiitb@iiitb-Dell-G15-5511

============================================================================
*/ 
