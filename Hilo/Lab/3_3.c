#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int user_num;
int num_1, num_2, num_3;
int fact_num = 1, fact_res = 1;
int sum;

void *thread_one( void *args )
{
    int sum_1 = 1;
    for(fact_num; fact_num <= num_1; fact_num++)
    {
    	fact_res *= fact_num;
        sum_1 *= fact_num;
    }
    printf("Este es el primer tercio = %d \n",num_1);
    printf("Esto es la multiplicacion del primer tercio: %d \n", sum_1);
printf("\n");
}

void *thread_two( void *args )
{
    int sum_2 = 1;
    for(fact_num; fact_num <= num_2; fact_num++)
    {
        fact_res *= fact_num;
        sum_2 *= fact_num;
    }
    printf("Este es el segundo tercio = %d \n", num_2);
    printf("Este es lo que llevo de la multiplicación: %d \n",sum_2);
    printf("\n");
}

void *thread_three( void *args )
{
    int sum_3 = 1;
    for(fact_num; fact_num <= num_3; fact_num++)
    {
        fact_res *= fact_num;
        sum_3 *= fact_num;
    }
    printf("Este es el segundo tercio = %d \n", num_3);
    printf("Este es lo que llevo de la multiplicación: %d \n",sum_3);
    printf("\n");
}

int main()
{
    pthread_t thread_1, thread_2, thread_3; // ID del hilo
    int state; // Valor de retorno de la creación del hilo
    printf("Dame un numero que sea divisible entre tres: ");
    scanf("%d", &user_num);

    if(user_num%3 == 0)
    {
    	num_1 = user_num / 3;
        num_2 = num_1 * 2;
        num_3 = user_num;
    	state = pthread_create( &thread_1, NULL, thread_one, NULL ); // Crear al hilo, call_return debe dar 0 o hay error
        state = pthread_create( &thread_2, NULL, thread_two, NULL);
        state = pthread_create( &thread_3, NULL, thread_three, NULL);
    	pthread_join( thread_1, NULL );
        pthread_join( thread_2, NULL );
        pthread_join( thread_3, NULL );
        printf("El factorial de %d es igual a %d \n", user_num, fact_res);
    }
    else
    {
    	printf("No es divisible entre tres \n");
        printf("Vuelve a ingresar el numero:");
        scanf("%d", &user_num);

    }
    return 0; // Terminar el proceso también mata a todos sus hilos secundarios
}

