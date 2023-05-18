#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t mutex; // for mutual exclusion of shared resources
sem_t *chopsticks; // array of semaphores for each chopstick
int num_philosophers; // number of philosophers

void *philosopher(void *arg) {
    int *pnum = (int *)arg;
    printf("Philosopher %d is thinking...\n", *pnum);
    while (1) {
        printf("Philosopher %d is hungry...\n", *pnum);
        pthread_mutex_lock(&mutex); // acquire mutex
        sem_wait(&chopsticks[*pnum]); // acquire left chopstick
        sem_wait(&chopsticks[(*pnum + 1) % num_philosophers]); // acquire right chopstick
        pthread_mutex_unlock(&mutex); // release mutex
        printf("Philosopher %d is eating...\n", *pnum);
        // do something with the chopsticks
        sem_post(&chopsticks[*pnum]); // release left chopstick
        sem_post(&chopsticks[(*pnum + 1) % num_philosophers]); // release right chopstick
        printf("Philosopher %d is thinking...\n", *pnum);
    }
    pthread_exit(NULL);
}

int main() {
    int i;
    pthread_t *philosophers;

    printf("Enter the number of philosophers: ");
    scanf("%d", &num_philosophers);

    philosophers = malloc(num_philosophers * sizeof(pthread_t));
    chopsticks = malloc(num_philosophers * sizeof(sem_t));

    // initialize the mutex and semaphores
    pthread_mutex_init(&mutex, NULL);
    for (i = 0; i < num_philosophers; i++) {
        sem_init(&chopsticks[i], 0, 1);
    }

    // create the philosopher threads
    for (i = 0; i < num_philosophers; i++) {
        int *pnum = malloc(sizeof(int));
        *pnum = i;
        pthread_create(&philosophers[i], NULL, philosopher, pnum);
    }

    // wait for the threads to finish
    for (i = 0; i < num_philosophers; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // destroy the mutex and semaphores
    pthread_mutex_destroy(&mutex);
    for (i = 0; i < num_philosophers; i++) {
        sem_destroy(&chopsticks[i]);
    }

    free(philosophers);
    free(chopsticks);

    return 0;
}
