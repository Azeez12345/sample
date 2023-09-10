#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(void)
{
	pid_t pid = fork();
	if(pid == 0)
	{
		printf("child -> ppid: %d pid:%d\n", getppid(),getpid());
	       exit(EXIT_SUCCESS);
	}
	else if(pid>0)
	{
		printf("parentid->pid: %d\n",getpid());
		wait(NULL);
		printf("Child process finished");
	}
	else
	{
		printf("unable to create child process");
	}
	return EXIT_SUCCESS;
}
