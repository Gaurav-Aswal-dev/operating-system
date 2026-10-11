#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#include <unistd.h>

#define SIZE 5

int buffer[SIZE];

int in = 0, out = 0;

sem_t empty;               
sem_t full;                
pthread_mutex_t lock;   
//producer   
void* producer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&empty); 
        pthread_mutex_lock(&lock);
        buffer[in] = i; 
        printf("Producer: item %d daala index %d pe\n", i, in);
        in = (in + 1) % SIZE;
        pthread_mutex_unlock(&lock);
        sem_post(&full);
        sleep(1);                   
    }
    return NULL;
}
// consumer
void* consumer(void* arg) {
    for (int i = 1; i <= 5; i++) {
        sem_wait(&full);            
        pthread_mutex_lock(&lock);   
        int item = buffer[out];      
        printf("Consumer: item %d nikala index %d se\n", item, out);
        out = (out + 1) % SIZE;      
        pthread_mutex_unlock(&lock); 
        sem_post(&empty);            
        sleep(2);                  
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