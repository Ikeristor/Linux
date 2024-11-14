#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS_NO 100
int count = 0;
pthread_mutex_t mutex_id;
pthread_cond_t cond_imp, cond_par;

void* print_impar( void *args )
{
    for(int i=0; i < THREADS_NO; i++)
    {
    pthread_mutex_lock( &mutex_id );
    while(count % 2 != 0)
    {
        pthread_cond_wait(&cond_imp, &mutex_id);
    }
    if(i % 2 == 0)
    {
        printf( "impar %d \n", i);
        count++;    
    }
    pthread_cond_signal( &cond_par );
    pthread_mutex_unlock( &mutex_id );
}
}

void* print_par( void *args )
{
    for(int i=0; i < THREADS_NO; i++)
    {
    pthread_mutex_lock( &mutex_id );
    while(count % 2 != 0)
    {
        pthread_cond_wait(&cond_par, &mutex_id);
    }
    if(i % 2 == 0)
    {
        printf( "par %d \n", i);
        count++;    
    }
    pthread_cond_signal( &cond_imp );
    pthread_mutex_unlock( &mutex_id );
    }
}

int main()
{
    pthread_t threads_par, threads_imp;

    pthread_mutex_init( &mutex_id, 0 ); 
    pthread_cond_init( &cond_imp, 0 );
    pthread_cond_init( &cond_par, 0 );

    pthread_create( &threads_par, NULL, print_par, NULL );
    pthread_create( &threads_imp, NULL, print_impar, NULL );

    pthread_join( threads_imp, NULL);
    pthread_join( threads_par, NULL);

    pthread_mutex_destroy( &mutex_id );
    pthread_cond_destroy( &cond_par );
    pthread_cond_destroy( &cond_imp );
    exit(0);
}