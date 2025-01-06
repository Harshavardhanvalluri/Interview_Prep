#include <stdio.h>
#include <pthread.h>

#define MAX_NUM 20

pthread_mutex_t mutex;
pthread_cond_t cond;
int count = 1;

void* printOdd(void* arg) {
    while (count <= MAX_NUM) {
        pthread_mutex_lock(&mutex);

        if (count % 2 != 0) {
            printf("Odd Thread: %d\n", count++);
            /// post sem
            pthread_cond_signal(&cond);
        } else {
            pthread_cond_wait(&cond, &mutex);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

void* printEven(void* arg) {
    while (count <= MAX_NUM) {
        pthread_mutex_lock(&mutex);

        if (count % 2 == 0) {
            printf("Even Thread: %d\n", count++);
            /// post sem
            pthread_cond_signal(&cond);
        } else {
            pthread_cond_wait(&cond, &mutex);
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t oddThread, evenThread;

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&oddThread, NULL, printOdd, NULL);
    pthread_create(&evenThread, NULL, printEven, NULL);

    pthread_join(oddThread, NULL);
    pthread_join(evenThread, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
