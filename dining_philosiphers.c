#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N 5
pthread_mutex_t fork_mutex[N];
// Ye ek trick hai function ko main ke andar rakhne ki (GCC me chalta hai)
// Agar teacher strict hai, toh isko normal function hi rakhna better hai.
int main() {
    pthread_t t[N];
    int a[N];

    // Thread function ko yahan define kar diya
    void* philosopher(void* arg) {
        int i = *(int*)arg;
        for (int j = 0; j < 3; j++) {
            printf("Philosopher %d is THINKING\n", i);
            sleep(1);
            
            printf("Philosopher %d is HUNGRY\n", i);
            if (i == 4) {
                pthread_mutex_lock(&fork_mutex[(i + 1) % N]); 
                pthread_mutex_lock(&fork_mutex[i]);
            } else {
                pthread_mutex_lock(&fork_mutex[i]);
                pthread_mutex_lock(&fork_mutex[(i + 1) % N]);
            }
            
            printf("Philosopher %d is EATING\n", i);
            sleep(2);
            
            pthread_mutex_unlock(&fork_mutex[i]);
            pthread_mutex_unlock(&fork_mutex[(i + 1) % N]);
        }
        return NULL;
    }

    for (int i = 0; i < N; i++) 
        pthread_mutex_init(&fork_mutex[i], NULL);

    for (int i = 0; i < N; i++) {
        a[i] = i;
        pthread_create(&t[i], NULL, philosopher, &a[i]);
    }

    for (int i = 0; i < N; i++) 
        pthread_join(t[i], NULL);

    for (int i = 0; i < N; i++) 
        pthread_mutex_destroy(&fork_mutex[i]);

    return 0;
}