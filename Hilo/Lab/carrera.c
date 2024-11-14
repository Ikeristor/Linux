#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int arr[5] = {0, 0, 0, 0, 0};
int user_num;
void *thread_change (void *args )
{
	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			if( i == 4)
			{
				if (arr[i] != 0)
				{
					printf("%d \n", arr[i]);
					printf("Ganaste \n");
					sleep(3);
					pthread_exit(NULL);
				}			
			}
			else
			{
				if (arr[i] != 0)
				{
					printf("%d \n", arr[i]);
					arr[i] = 0;
				}
			}
		}
	}
}

int main ()
{
	pthread_t thread_1;
	int states;
	states = pthread_create( &thread_1, NULL, thread_change, NULL);
	printf("Pon un numero más rapido que yo \n");
	while(1)
	{
		for(int i = 0; i < 5; i++)
		{
			scanf("%d", &user_num);
			arr[i] = user_num;		
		}
	}
	return 0;
}