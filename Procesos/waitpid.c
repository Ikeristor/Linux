#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
pid_t pid_A, pid_B, pid_C;
int status;
pid_A = fork();
// Child process
if( pid_A == 0 )
{
sleep(3);
return 1;
}
else
{
pid_B = fork();
if( pid_B == 0 )
{
return 2;
}
else
{
pid_C = fork();
if( pid_C == 0 )
{
sleep(10);
return 3;
}
}
}
if( pid_B > 0)
{

waitpid(pid_B, &status, 0);
printf("El proceso B ha terminado con el status: %d.\n",

WEXITSTATUS(status));
}
if( pid_A > 0)
{
waitpid(pid_A, &status, 0);
printf("El proceso A ha terminado con el status: %d.\n",

WEXITSTATUS(status));
}
if( pid_C > 0)
{
waitpid(pid_C, &status, 0);
printf("El proceso C ha terminado con el status: %d.\n",

WEXITSTATUS(status));
}
return 0;
}
