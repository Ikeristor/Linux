/*
    Counter based on threads. 
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int counter = 0;
#define N_THREADS 50000
sem_t semaphore_id;

// Declare the semaphore as a global variable so that the threads can use it.


void* increase_counter(void* arg) 
{
    int i;
    for ( int i=0; i<100; i++) 
    {
        sem_wait(&semaphore_id);
        counter = counter + 1;
        sem_post(&semaphore_id);
    }
    pthread_exit( NULL );
}

int main() 
{
    pthread_t thread_ids[N_THREADS];
    sem_init(&semaphore_id, 0, 1);
    // Create the semaphore.
    
    // Create children.
    for( int i=0; i<N_THREADS; i++)
        pthread_create( &thread_ids[i], NULL, increase_counter, NULL );
    
    // Wait for the children to finish.
    for( int i=0; i<N_THREADS; i++)
        pthread_join( thread_ids[i], NULL );
    
    sem_destroy(&semaphore_id);
    // Destroy the semaphore.

    printf("El valor final del contador es %d\n", counter);
    return 0;
}