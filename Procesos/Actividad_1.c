#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int error_check (int fd)
{

if (fd < 0)
    {
        if(errno == EAGAIN)
        {
                printf("Archivo bloqueado.\n");
                return(1);
        }
	else if( errno == EACCES)
        {
                printf("Problema de permisos del archivo. \n");
                return(1);
        }
	else if( errno == EBADF)
        {
                printf("Mal descriptor del archivo. \n");
                return(1);
        }
	else
	    {
                printf("Error desconocido. \n");
                return(1);
        }
    }
return 0;
}
int main()
{

int fd,n;
//Change variable name
float arreglo[5]={6,7,8,4,2};
fd = creat("datos.txt", 777);
n = write(fd, arreglo, sizeof(arreglo));



close(fd);
return 0;
}
