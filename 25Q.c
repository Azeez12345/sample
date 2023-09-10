#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<sys/wait.h>
#include<sys/types.h>
void main()
{
        int p = fork();;
        if(p == 0)
	{
		printf("I am The 1St child: %d\n",getpid());
		printf("Parent of 1st: %d\n",getppid());
	}
	else if(p > 0)
        {
		int p1 = fork();
		if(p1 == 0)
		{
			sleep(4);
			printf("I am the second child: %d\n",getpid());
			printf("My parent: %d\n",getppid());
		}
		else if(p1>0)
		{
			int p2 = fork();
			if(p2 == 0)
			{
				printf("I am the third child: %d\n",getpid());
				printf("My parent: %d\n",getppid());
			}
			else if(p2>0)
			{
				waitpid(p1,WIFEXITED(2),WCONTINUED);
				printf("Main Parent: %d\n",getpid());
			}
		}
        }
}

