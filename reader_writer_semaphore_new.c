#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

sem_t rd, wr;
int a = 1, readcount = 0;

void* reader(void* arg)
{
    int num = *(int*)arg;
    while (1) {
        sem_wait(&rd);
        readcount++;
        if (readcount == 1) {
            sem_wait(&wr);
        }
        sem_post(&rd);

        printf("\nReader %d reads %d", num, a);

        sem_wait(&rd);
        readcount--;
        if (readcount == 0) {
            sem_post(&wr);
        }
        sem_post(&rd);

        sleep(1);
    }
}

void* writer(void* arg)
{
    int num = *(int*)arg;
    while (1) {
        sem_wait(&wr);

        printf("\nWriter %d writes %d\n", num, a++);

        sem_post(&wr);
        sleep(1);
    }
}

int main()
{
    pthread_t r[10], w[10];
    sem_init(&rd, 0, 0);
    sem_init(&wr, 0, 1);

    int re, wi;
    int read[10], write[10];
    printf("Enter the number of readers and writers:\n");
    scanf("%d %d", &re, &wi);

    for (int i = 0; i < re; i++) {
        read[i] = i;
        pthread_create(&r[i], NULL, reader, &read[i]);
    }

    for (int j = 0; j < wi; j++) {
        write[j] = j;
        pthread_create(&w[j], NULL, writer, &write[j]);
    }

    for (int i = 0; i < re; i++) {
        pthread_join(r[i], NULL);
    }

    for (int j = 0; j < wi; j++) {
        pthread_join(w[j], NULL);
    }
}
