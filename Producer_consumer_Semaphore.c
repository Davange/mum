#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0; // points to the next available slot in buffer
int out = 0; // points to the next item to be removed from buffer

sem_t empty; // declare an empty semaphore
sem_t full; // declare a full semaphore
pthread_mutex_t mutex; // declare a mutex

void *producer(void *arg) {
    int i, item;
    int *pnum = (int *)arg;
    for (i = 0; i < *pnum; i++) { // produce pnum items
        printf("Enter a number to add to the buffer: ");
        scanf("%d", &item);
        sem_wait(&empty); // wait for an empty slot in buffer
        pthread_mutex_lock(&mutex); // acquire the mutex before accessing the buffer
        buffer[in] = item; // add the item to the buffer
        in = (in + 1) % BUFFER_SIZE; // update in pointer
        pthread_mutex_unlock(&mutex); // release the mutex
        sem_post(&full); // signal that a slot is now full
    }
    pthread_exit(NULL);
}

void *consumer(void *arg) {
    int i, item;
    int *cnum = (int *)arg;
    for (i = 0; i < *cnum; i++) { // consume cnum items
        sem_wait(&full); // wait for a full slot in buffer
        pthread_mutex_lock(&mutex); // acquire the mutex before accessing the buffer
        item = buffer[out]; // remove an item from the buffer
        out = (out + 1) % BUFFER_SIZE; // update out pointer
        pthread_mutex_unlock(&mutex); // release the mutex
        sem_post(&empty); // signal that a slot is now empty
        printf("Consumed: %d\n", item); // do something with the item
    }
    pthread_exit(NULL);
}

int main() {
    int pnum, cnum;
    pthread_t producer_thread, consumer_thread;

    printf("Enter the number of items to produce: ");
    scanf("%d", &pnum);
    printf("Enter the number of items to consume: ");
    scanf("%d", &cnum);

    // initialize the semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // create the producer and consumer threads
    pthread_create(&producer_thread, NULL, producer, &pnum);
    pthread_create(&consumer_thread, NULL, consumer, &cnum);

    // wait for the threads to finish
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // destroy the semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
