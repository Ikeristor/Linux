#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{

int fd,n;
float arreglo[5];


fd = open("datos.txt",2);

n = read(fd, arreglo, sizeof(arreglo));

for (int i = 0; i < 5; i++)
        {
	printf("%f\n",arreglo[i]);
        }
close(fd);
return 0;
}
