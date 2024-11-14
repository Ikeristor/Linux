#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void signal_handler_sigusr1(int signum)
{
   printf("Recibí la señal SIGUSR1 \n ID de padre %d ID de hijo A  %d \n",getppid(),getpid());
}
void signal_handler_sigusr2(int signum)
{
   printf("Recibí la señal SIGUSR2 \n ID de padre %d ID de hijo C  %d \n",getppid(),getpid());
}

void sig_handler(int signum)
{
  printf("Alarma recibida \n");
}


int main() 
{
    pid_t pid_A, pid_C;
    int status;

 signal(SIGALRM,sig_handler);
  alarm(3);
  sleep(3);
    pid_A = fork();

    if (pid_A == 0) 
    {
	pid_C = fork();
        if(pid_C == 0)
                {
                // Proceso hijo
                signal(SIGUSR2, signal_handler_sigusr2);
                pause();
		return 0;
                }
     	// Proceso hijo
        signal(SIGUSR1, signal_handler_sigusr1);
        pause();
	kill(pid_C, SIGUSR2);
	waitpid(pid_C, &status, 0);
        return 0;
    } 
    else if (pid_A > 0) 
    {
     	// Proceso padre
        sleep(1);
        kill(pid_A, SIGUSR1);
        wait(&status);
	waitpid(pid_A, &status, 0);
	printf("Mis hijos han terminado");
    }
    return 0;
}

