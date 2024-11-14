#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int num_son;
char name_son;
void signal_handler_sigus1(int signum)
{

}
void signal_handler_sigus2(int signum)
{

}

int main()
{
	pid_t pidZ, pidT;
	while(1)
	{
		printf("Dame el nombre de un hijo: ");
		scanf("%d",&name_son);
		if(name_son == 'Z' || name_son == 'z')
		{
			fork = pidZ
			if(num_son == 1)
			{
				signal(SIGUSR1, signal_handler_sigus1);

			}	
			else if(num_son == 2)
			{
				signal(SIGUSR2, signal_handler_sigus2);
			}
		}else if(name_son == 'T' || name_son == 't')
		{
			fork = pidT;
			if(num_son == 1)
			{
				signal(SIGUSR1, signal_handler_sigus1);

			}	
			else if(num_son == 2)
			{

				signal(SIGUSR2, signal_handler_sigus2);
			}
		}
		exit (0);
	}
}