#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{

int fd, n;
float number_1, number_2, number_3, number_4, number_5;

number_1 = 4;
number_2 = 0;
number_3 = 23;
number_4 = 42;
number_5 = 345;

fd =  creat("datos2.txt", 777);
n = write(fd, &number_1,sizeof(number_1));

n = write(fd, &number_2,sizeof(number_2));

n = write(fd, &number_3,sizeof(number_3));

n = write(fd, &number_4,sizeof(number_4));

n = write(fd, &number_5,sizeof(number_5));
close (fd);
return 0;

}

