#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREADS_NO 10

/* Print hello world and kill the thread. */
void* print_par( void *args )
{
    printf( "par\n" );
    pthread_exit( NULL );
}
void* print_impar( void *args )
{
    printf( "impar\n" );
    pthread_exit( NULL );
}



int main()
{
    pthread_t threads[THREADS_NO];
    int state, i;
    
    for(i=0; i < THREADS_NO; i++) 
    {
        if (i % 2 == 0)
            {
                pthread_create( &threads[i], NULL, print_par, NULL );
                printf( "Main creo un hilo en la iteración %d.\n", i );
            }
        else
            {
                pthread_create( &threads[i], NULL, print_impar, NULL );
                printf( "Main creo un hilo en la iteración %d.\n", i );
            }
        pthread_join(threads[i], NULL );    
    }
    
    exit(0);
}