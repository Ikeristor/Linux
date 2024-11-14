#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
pid_t pid;
int fd,n;
float arreglo[5]={4,6,3,2,7};
pid = fork();

if(pid == 0)
{
fd = creat("datos.txt", 777);
n = write(fd, arreglo, sizeof(arreglo));
}

if(pid > 0)
{
sleep (3);
fd = open("datos.txt",2);
n = read(fd, arreglo, sizeof(arreglo));
for (int i = 0; i < 5; i++)
	{
	printf("%f\n",arreglo[i]);
	}
}

close(fd);
return 0;
}
