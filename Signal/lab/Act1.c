#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler_sigint(int signum)
{
   printf("El usuario presionó CTRL+C \n");
   sleep(3);
}
int main() 
{
    int satutus;
	signal(SIGINT, signal_handler_sigint);
    	while(1)
    	{
    	printf("%d \n",getpid);
	sleep(1);
    	}
    return 0;
}
