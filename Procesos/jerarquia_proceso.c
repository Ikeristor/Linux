#include<sys/wait.h>
#include<wait.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<asm-generic/errno-base.h>
#include<errno.h>
#include<sys/types>
#include<fcntl.h>
#include<time.h>

int main()
{
pid_t  pid_A, pid_B, pid_M;
int n, m, fd, status;

pid_A = fork();

if (pid_A == 0)
{
	printf("Tu Id de hijo A es %d \n ", getpid());
	return (0);
	exit(0);
}
pid_B = fork();

if (pid_B == 0)
{
	printf("Tu Id de hijo B es %d \n ", getpid());
        return (0);
        exit(0);
}
pid_M = fork();

if (pid_M == 0)
{
        printf("Tu Id de hijo M es %d \n ", getpid());
        return (0);
        exit(0);
}

close(fd);
return 0;
}
