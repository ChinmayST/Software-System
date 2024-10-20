/*
============================================================================
Name : 31a.c
Author : Chinmay Tavarej
Description : Write a program to create a semaphore and initialize value to the semaphore. - Create a binary semaphore
Date: 10th Oct , 2024
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // For sleep()

// Global semaphore variable
sem_t binary_semaphore;

void *thread_function(void *arg) {
    // Wait (decrement) the semaphore
    sem_wait(&binary_semaphore);
    printf("Thread %ld: Entered critical section.\n", (long)arg);
    
    // Simulate some work in the critical section
    sleep(2);

    printf("Thread %ld: Exiting critical section.\n", (long)arg);
    
    // Signal (increment) the semaphore
    sem_post(&binary_semaphore);
    
    return NULL;
}

int main() {
    pthread_t threads[2];

    // Initialize the binary semaphore with a value of 1
    if (sem_init(&binary_semaphore, 0, 1) != 0) {
        perror("Failed to initialize semaphore");
        exit(EXIT_FAILURE);
    }

    // Create two threads that will use the semaphore
    for (long i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, (void *)i) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for both threads to complete execution & makes main process wait
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&binary_semaphore);

    return 0;
}
/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/31$ gcc 31a.c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/31$ ./a.out
Thread 0: Entered critical section.
Thread 0: Exiting critical section.
Thread 1: Entered critical section.
Thread 1: Exiting critical section.



============================================================================
*/ 
