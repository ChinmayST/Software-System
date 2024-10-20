/*
============================================================================
Name : 31b.c
Author : Chinmay Tavarej
Description : Write a program to create a semaphore and initialize value to the semaphore. - Create a counting semaphore
Date: 10th Oct , 2024
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // For sleep()

#define MAX_RESOURCES 3 // Maximum resources

// Global semaphore variable
sem_t counting_semaphore;

void *thread_function(void *arg) {
    int thread_id = *(int *)arg;

    // Wait (decrement) the semaphore
    sem_wait(&counting_semaphore);
    printf("Thread %d: Entered critical section.\n", thread_id);
    
    // Simulate some work in the critical section
    sleep(2);
    
    printf("Thread %d: Exiting critical section.\n", thread_id);
    
    // Signal (increment) the semaphore
    sem_post(&counting_semaphore);
    
    return NULL;
}

int main() {
    pthread_t threads[5];
    int thread_ids[5];

    // Initialize the counting semaphore with a value of MAX_RESOURCES
    if (sem_init(&counting_semaphore, 0, MAX_RESOURCES) != 0) {
        perror("Failed to initialize semaphore");
        exit(EXIT_FAILURE);
    }

    // Create multiple threads that will use the semaphore
    for (int i = 0; i < 5; i++) {
        thread_ids[i] = i; // Assign thread ID
        if (pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&counting_semaphore);

    return 0;
}
/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/31$ gcc 31b.c -o 31b
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/31$ ./31b
Thread 0: Entered critical section.
Thread 1: Entered critical section.
Thread 2: Entered critical section.
Thread 0: Exiting critical section.
Thread 1: Exiting critical section.
Thread 3: Entered critical section.
Thread 4: Entered critical section.
Thread 2: Exiting critical section.
Thread 3: Exiting critical section.
Thread 4: Exiting critical section.


============================================================================
*/ 
