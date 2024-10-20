/*
============================================================================
Name : 32c.c
Author : Chinmay Tavarej
Description : Write a program to implement semaphore to protect any critical section - Protect multiple pseudo resources (may be two) using counting semaphore 
Date: 10th Oct , 2024
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define RES 2  // Total resources
#define THR 5  // Number of threads

sem_t sem;  // Semaphore for resource access

void *rsrc(void *arg) {
    int id = *(int *)arg;

    while (1) {
        sem_wait(&sem);  // Acquire resource

        printf("T%d: Acquired a resource.\n", id);
        
        sleep(1);  // Simulate resource usage

        printf("T%d: Released a resource.\n", id);
        
        sem_post(&sem);  // Release resource

        sleep(1);  // Processing time
    }

    return NULL;
}

int main() {
    pthread_t t[THR];
    int ids[THR];

    sem_init(&sem, 0, RES);  // Initialize semaphore

    for (int i = 0; i < THR; i++) {
        ids[i] = i;  // Assign thread ID
        if (pthread_create(&t[i], NULL, rsrc, (void *)&ids[i]) != 0) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < THR; i++) {
        pthread_join(t[i], NULL);  // Wait for threads to finish
    }

    sem_destroy(&sem);  // Clean up semaphore

    return 0;
}

/*
============================================================================
Output : 
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/32$ gcc 32c.c -o 32c
iiitb@iiitb-Dell-G15-5511:~/Hands-On-List-2/32$ ./32c
T1: Acquired a resource.
T0: Acquired a resource.
T1: Released a resource.
T0: Released a resource.
T2: Acquired a resource.
T3: Acquired a resource.
T2: Released a resource.
T4: Acquired a resource.
T3: Released a resource.
T0: Acquired a resource.
T4: Released a resource.
.
.
.
continue 


============================================================================
*/ 
