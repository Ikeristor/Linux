#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main( )
{
pid_t pid_T, pid_W;

printf("Soy el padre R y mi pid es %d \n",getpid());

pid_T = fork();

if(pid_T == 0)
{
printf("Soy hijo de R su pid es %d soy T y mi pid es %d \n",getppid(),getpid());
pid_t pid_V;

pid_V = fork();
	if(pid_V == 0)
	{
	printf("Soy hijo de T su pid es %d soy V y mi pid es %d \n",getppid(),getpid());
	}
exit(0);
}

pid_W = fork();

if (pid_W == 0)
{
printf("Soy hijo de R su pid es %d soy W y mi pid es %d \n",getppid(),getpid());
pid_t pid_S, pid_L;
pid_S = fork();
	if(pid_S == 0)
	{
	printf("Soy hijo de W su pid es %d soy S y mi pid es %d \n",getppid(),getpid());
	exit(0);
	}
pid_L = fork();
	if(pid_L == 0)
	{
	printf("Soy hijo de W su pid es %d soy L y mi pid es %d \n",getppid(),getpid());
	pid_t pid_P;
	pid_P = fork();
		if(pid_P == 0)
		{
		printf("Soy hijo de L su pid es %d soy P y mi pid es %d \n",getppid(),getpid());
		exit(0);
		}
	exit(0);
	}
exit(0);
}
return 0;
}


