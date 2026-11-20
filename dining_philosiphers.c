#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t fork[5];

void* eat(void* arg)
{
    int i = *(int*)arg;
    while (1) {
        printf("Philosopher %d is THINKING\n", i);
        sleep(1);
        if (i == 4) {
            pthread_mutex_lock(&fork[(i + 1) % 5]);  // right pehle
            pthread_mutex_lock(&fork[i]);            // left baad mein
        } else {
            pthread_mutex_lock(&fork[i]);            // left pehle
            pthread_mutex_lock(&fork[(i + 1) % 5]);  // right baad mein
        }

        // 3. EATING
        printf("Philosopher %d is EATING (using forks %d and %d)\n",
               i, i, (i + 1) % 5);
        sleep(2);

        // 4. RELEASE — forks chhod do
        pthread_mutex_unlock(&fork[i]);
        pthread_mutex_unlock(&fork[(i + 1) % 5]);

        printf("Philosopher %d finished eating and released forks\n", i);
    }
    return NULL;
}

int main()
{
    pthread_t t[5];
    int i, a[5];

    // Har fork ka mutex initialize karo
    for (i = 0; i < 5; i++)
        pthread_mutex_init(&fork[i], NULL);

    // Har philosopher ke liye thread banao
    for (i = 0; i < 5; i++) {
        a[i] = i;
        pthread_create(&t[i], NULL, eat, &a[i]);
    }

    // Threads ke khatam hone ka wait
    for (i = 0; i < 5; i++)
        pthread_join(t[i], NULL);

    // Mutex destroy karo
    for (i = 0; i < 5; i++)
        pthread_mutex_destroy(&fork[i]);

    return 0;
}