#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex; // for mutual exclusion of shared resources
sem_t write_mutex; // for mutual exclusion of writers
int read_count = 0; // number of readers currently accessing the resource

void *reader(void *arg) {
    int *rnum = (int *)arg;
    printf("Reader %d is trying to access the resource...\n", *rnum);
    sem_wait(&mutex); // acquire mutex for mutual exclusion of shared resources
    read_count++;
    if (read_count == 1) { // first reader
        sem_wait(&write_mutex); // acquire write_mutex to exclude writers
    }
    sem_post(&mutex); // release mutex
    printf("Reader %d is reading the resource...\n", *rnum);
    // do something with the resource
    sem_wait(&mutex); // acquire mutex again
    read_count--;
    if (read_count == 0) { // last reader
        sem_post(&write_mutex); // release write_mutex to allow writers
    }
    sem_post(&mutex); // release mutex
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int *wnum = (int *)arg;
    printf("Writer %d is trying to access the resource...\n", *wnum);
    sem_wait(&write_mutex); // acquire write_mutex for mutual exclusion of writers
    printf("Writer %d is writing to the resource...\n", *wnum);
    // do something with the resource
    sem_post(&write_mutex); // release write_mutex
    pthread_exit(NULL);
}

int main() {
    int num_readers, num_writers, i;
    pthread_t *readers, *writers;

    printf("Enter the number of readers: ");
    scanf("%d", &num_readers);
    printf("Enter the number of writers: ");
    scanf("%d", &num_writers);

    // allocate memory for the readers and writers
    readers = (pthread_t *)malloc(num_readers * sizeof(pthread_t));
    writers = (pthread_t *)malloc(num_writers * sizeof(pthread_t));

    // initialize the semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&write_mutex, 0, 1);

    // create the reader threads
    for (i = 0; i < num_readers; i++) {
        pthread_create(&readers[i], NULL, reader, &i);
    }

    // create the writer threads
    for (i = 0; i < num_writers; i++) {
        pthread_create(&writers[i], NULL, writer, &i);
    }

    // wait for the threads to finish
    for (i = 0; i < num_readers; i++) {
        pthread_join(readers[i], NULL);
    }
    for (i = 0; i < num_writers; i++) {
        pthread_join(writers[i], NULL);
    }

    // destroy the semaphores
    sem_destroy(&mutex);
    sem_destroy(&write_mutex);

    // free the memory
    free(readers);
    free(writers);

    return 0;
}
