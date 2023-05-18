#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *producer(void *arg) {
    int item;
    while (1) {
        printf("Enter item to produce: ");
        scanf("%d", &item);
        pthread_mutex_lock(&mutex);
        if (count == BUFFER_SIZE) {
            printf("Buffer is full. Producer is waiting...\n");
            pthread_mutex_unlock(&mutex);
            continue;
        }
        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Produced item %d\n", item);
        pthread_mutex_unlock(&mutex);
    }
}

void *consumer(void *arg) {
    int item;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (count == 0) {
            printf("Buffer is empty. Consumer is waiting...\n");
            pthread_mutex_unlock(&mutex);
            continue;
        }
        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumed item %d\n", item);
        pthread_mutex_unlock(&mutex);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    return 0;
}
