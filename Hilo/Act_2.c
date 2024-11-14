/*
    Programa que inicia un hilo secundario que aumenta un contador indefinidamente.
    El hilo principal espera una entrada del teclado, y cuando la recibe imprime el valor del contador.
    
    Programa basado en la versión de Daniel Sol Llaven 2015-03-31 (Sistemas Operativos Panorama para ingeniería en computación e informática, pag. 54).
*/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int counter;

void sig_handler(int signum)
{
  printf("Tardaste mucho\n");
  kill(getpid(), SIGKILL);
}

void* increase_counter( void *args )
{
    while(1)
    {
        counter++;
        sleep(1);
    }
    pthread_exit( NULL );
}

int main()
{
    pthread_t thread_1; // ID del hilo
    int state; // Valor de retorno de la creación del hilo
    counter = 0;    // La cuenta empieza en 0
    
    state = pthread_create( &thread_1, NULL, &increase_counter, NULL ); // Crear al hilo, call_return debe dar 0 o hay error

    printf("Contando. Presiona cualquier tecla para ver la cuenta.\n");
    while(1)
    {
        getchar();
        printf("El contador llegó a: %d.\n", counter);
        if (counter == 3)
        {
            signal(SIGALRM,sig_handler); // Register signal handler
            alarm(2); 
        }
    }  
    exit(0); // Terminar el proceso también mata a todos sus hilos secundarios
}