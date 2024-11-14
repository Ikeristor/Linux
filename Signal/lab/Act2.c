#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_handler(int signum)
{
  printf("Transcurrieron 3 segundos \n");
}
int main()
{
  signal(SIGALRM,sig_handler); // Register signal handler

  alarm(3);  // Scheduled alarm after 2 seconds

 for(int i;;i++)
{
 sleep(1);
}
return 0;
}
