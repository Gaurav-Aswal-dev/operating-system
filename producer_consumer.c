#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5              // Buffer ki size

int buffer[SIZE];           // Buffer (5 items rakh sakte hain)
int in = 0, out = 0;        // Producer daalta hai 'in' pe, Consumer nikaalta hai 'out' se

sem_t empty;                // Kitni jagah khaali hai
sem_t full;                 // Kitne items bhare hue hain
pthread_mutex_t lock;       // Lock (ek time par ek hi thread)

// 🟢 PRODUCER FUNCTION
void* producer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&empty);           // 1. Khaali jagah check karo
        pthread_mutex_lock(&lock);   // 2. Lock lagao

        buffer[in] = i;              // 3. Item daalo
        printf("Producer: item %d daala index %d pe\n", i, in);
        in = (in + 1) % SIZE;        // 4. in ko aage badhao (circular)

        pthread_mutex_unlock(&lock); // 5. Lock kholo
        sem_post(&full);             // 6. Full signal do (1 item badha)

        sleep(1);                    // 1 second ruko
    }
    return NULL;
}

// 🔴 CONSUMER FUNCTION
void* consumer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&full);             // 1. Item check karo
        pthread_mutex_lock(&lock);   // 2. Lock lagao

        int item = buffer[out];      // 3. Item nikalo
        printf("Consumer: item %d nikala index %d se\n", item, out);
        out = (out + 1) % SIZE;      // 4. out ko aage badhao (circular)

        pthread_mutex_unlock(&lock); // 5. Lock kholo
        sem_post(&empty);            // 6. Empty signal do (1 jagah khaali)

        sleep(2);                    // 2 second ruko
    }
    return NULL;
}

int main() {
    pthread_t p, c;                  

    sem_init(&empty, 0, SIZE);       
    sem_init(&full, 0, 0);           
    pthread_mutex_init(&lock, NULL); 
    

    pthread_create(&p, NULL, producer, NULL);  
    pthread_create(&c, NULL, consumer, NULL);  

    pthread_join(p, NULL);           
    pthread_join(c, NULL);           

    return 0;
}