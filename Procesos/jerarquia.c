#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void fillEvenArray(int fd){
    int tempArray[10] = {2,4,6,8,10,12,14,16,18,20};
    for(int i = 0; i < 10;i++) {
        write(fd,&tempArray[i],sizeof(tempArray[0]));
    }
}

void fillOddArray(int fd){
    int tempArray[10] = {1,3,5,7,9,11,13,15,17,19};
    for(int i = 0; i < 10;i++) {
        write(fd,&tempArray[i],sizeof(tempArray[0]));
    }
}
void sumArrays(int fd1, int fd2){
    int tempArray[10];
    int tempArray2[10];
    int resultArray[10];
    for(int i = 0; i < 10;i++) {
        read(fd1,&tempArray[i],sizeof(tempArray[0]));
        read(fd2,&tempArray2[i],sizeof(tempArray[0]));
        resultArray[i] = tempArray[i] + tempArray2[i];
    }
    printf("Result Array:\n");
    for(int i = 0; i < 10;i++) {
        if(i < 9)
        {
            printf(" %d + %d = %d \n",tempArray2[i],tempArray[i],resultArray[i]);
        } else
	{
            printf(" %d + %d = %d \n ",tempArray2[i], tempArray[i],resultArray[i]);
        }
    }

}

void printArrayFromFile(int fd){
    int tempArray[5];
    for(int i = 0; i < 5;i++) {
        read(fd,&tempArray[i],sizeof(tempArray[0]));
        if(i < 4)
        {
            printf(" %d,",tempArray[i]);
        } else
	{
            printf(" %d ",tempArray[i]);
        }
    }
}

int main() {
    creat("N.txt",111111111);
    creat("M.txt",111111111);
    pid_t pid_n,pid_m,p;

    pid_n = fork();


    if( pid_n == 0)
    {
     	int fd;
        fd = open("N.txt",1);
        fillEvenArray(fd);
        close(fd);
        exit(0);

    }
    pid_m = fork();

    if( pid_m == 0)
    {
     	int fd;
        fd = open("M.txt",1);
        fillOddArray(fd);
        close(fd);
        exit(0);

    }

    if( pid_n > 0 && pid_m > 0)
    {
     	sleep(3);
        int fd;
        int fd_2;
        fd = open("N.txt",0);
        fd_2 = open("M.txt",0);
        sumArrays(fd,fd_2);
        close(fd);
        close(fd_2);
    }
    printf("\n");

    return 0;
}
