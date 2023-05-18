#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex; // for mutual exclusion of shared resources
pthread_mutex_t write_mutex; // for mutual exclusion of writers
int read_count = 0; // number of readers currently accessing the resource

void *reader(void *arg) {
    int rnum = *(int *)arg;
    printf("Reader %d is trying to access the resource...\n", rnum);
    pthread_mutex_lock(&mutex); // acquire mutex for mutual exclusion of shared resources
    read_count++;
    if (read_count == 1) { // first reader
        pthread_mutex_lock(&write_mutex); // acquire write_mutex to exclude writers
    }
    pthread_mutex_unlock(&mutex); // release mutex
    printf("Reader %d is reading the resource...\n", rnum);
    // do something with the resource
    pthread_mutex_lock(&mutex); // acquire mutex again
    read_count--;
    if (read_count == 0) { // last reader
        pthread_mutex_unlock(&write_mutex); // release write_mutex to allow writers
    }
    pthread_mutex_unlock(&mutex); // release mutex
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int wnum = *(int *)arg;
    printf("Writer %d is trying to access the resource...\n", wnum);
    pthread_mutex_lock(&write_mutex); // acquire write_mutex for mutual exclusion of writers
    printf("Writer %d is writing the resource...\n", wnum);
    // do something with the resource
    pthread_mutex_unlock(&write_mutex); // release write_mutex
    pthread_exit(NULL);
}

int main() {
    int num_readers, num_writers;
    printf("Enter the number of readers: ");
    scanf("%d", &num_readers);
    printf("Enter the number of writers: ");
    scanf("%d", &num_writers);

    pthread_t readers[num_readers], writers[num_writers];
    int reader_ids[num_readers], writer_ids[num_writers];

    // Initialize mutexes
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&write_mutex, NULL);

    // Create reader threads
    for (int i = 0; i < num_readers; i++) {
        reader_ids[i] = i;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < num_writers; i++) {
        writer_ids[i] = i;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < num_readers; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < num_writers; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy mutexes
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&write_mutex);

    return 0;
}
