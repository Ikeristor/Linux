#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int father_array[12] = {1, 2, 3, 4 ,5 ,6 ,7 ,8 ,9 ,10 ,11 ,12};
int child_1[4], child_2[4], child_3[4];
int found_flag = 0;
int user_num;
void *thread_one( void *args )
{
	for(int i = 0; i < 4; i++)
	{
		int chec = child_1[i];
		if(user_num == chec)
		{
			found_flag = 1;
			pthread_exit(NULL);
		}
	}

}

void *thread_two( void *args )
{
	for(int i = 0; i < 4; i++)
	{
		int chec = child_2[i];
		if(user_num == chec)
		{
			found_flag = 1;
			pthread_exit(NULL);
		}
	}
}

void *thread_three( void *args )
{
	for(int i = 0; i < 4; i++)
	{
		int chec = child_3[i];
		if(user_num == chec)
		{
			found_flag = 1;
			pthread_exit(NULL);
		}
	}
}

int main()
{
	int counter = 0;
	int state;
	pthread_t thread_1, thread_2, thread_3;
	printf("Papá: \n ");
    for (int i = 0; i < 12; i++) {
        printf("%d \n", father_array[i]);
    }
	for(int i = 0; i < 4; i++)
	{
		child_1[i] = father_array[counter];
		counter ++;
	}
	printf("Hijo 1: \n ");
    for (int i = 0; i < 4; i++) {
        printf("%d \n", child_1[i]);
    }
    for(int i = 0; i < 4; i++)
	{
		child_2[i] = father_array[counter];
		counter ++;
	}
	printf("Hijo 2: \n ");
    for (int i = 0; i < 4; i++) {
        printf("%d \n", child_2[i]);
    }
    for(int i = 0; i < 4; i++)
	{
		child_3[i] = father_array[counter];
		counter ++;
	}
	printf("Hijo 3: \n ");
    for (int i = 0; i < 4; i++) {
        printf("%d \n", child_3[i]);
    }
   	printf("Qué numero buscas?  ");
   	scanf("%d", &user_num);
    state = pthread_create( &thread_1, NULL, thread_one, NULL ); // Crear al hilo, call_return debe dar 0 o hay error
    state = pthread_create( &thread_2, NULL, thread_two, NULL);
    state = pthread_create( &thread_3, NULL, thread_three, NULL);
	pthread_join( thread_1, NULL );
    pthread_join( thread_2, NULL );
    pthread_join( thread_3, NULL );

    if (found_flag != 0)
    {
    	printf("El numero %d si fue encontrado \n",user_num);
    }
    else
    {
    	printf("El numero %d no fue encontrado \n",user_num);
    }
    return 0;
}
