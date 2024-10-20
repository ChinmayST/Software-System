/*
============================================================================
Name : 32a.c
Author : Chinmay Tavarej
Description : Write a program to implement semaphore to protect any critical section - Rewrite the ticket number creation program using semaphore
Date: 10th Oct , 2024
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h> // For sleep()

#define MAX_TICKETS 10 // Total number of tickets
#define NUM_THREADS 5   // Number of threads

sem_t semaphore; // Semaphore to protect the critical section
int ticket_number = 0; // Global ticket number

void *generate_ticket(void *arg) {
    int thread_id = *(int *)arg;

    while (1) {
        // Wait (decrement) the semaphore
        sem_wait(&semaphore);

        if (ticket_number < MAX_TICKETS) {
            ticket_number++;
            printf("Thread %d: Generated ticket number %d\n", thread_id, ticket_number);
        } else {
            // If no more tickets are available, signal and exit
            sem_post(&semaphore)2;
            break;
        }

        // Signal (increment) the semaphore
        sem_post(&semaphore);

        // Simulate some processing time
        sleep(1);
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the semaphore with a value of 1
    sem_init(&semaphore, 0, 1);

    // Create multiple threads that will generate ticket numbers
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i; // Assign thread ID
        if (pthread_create(&threads[i], NULL, generate_ticket, (void *)&thread_ids[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}
/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/32$ gcc 32a.c -o 32a
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/32$ ./32a
Thread 0: Generated ticket number 1
Thread 4: Generated ticket number 2
Thread 2: Generated ticket number 3
Thread 1: Generated ticket number 4
Thread 3: Generated ticket number 5
Thread 0: Generated ticket number 6
Thread 2: Generated ticket number 7
Thread 4: Generated ticket number 8
Thread 1: Generated ticket number 9
Thread 3: Generated ticket number 10


============================================================================
*/ 
