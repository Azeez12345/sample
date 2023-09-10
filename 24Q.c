#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/resource.h>
#include<sys/time.h>
void main()
{
        int p = fork();
        if(p>0)
        {
                printf("Parent Executed: %d\n",getpid());
        }
        else if(p == 0)
        {
		sleep(2);
                printf("Child Executed: %d\n",getpid());
        }
}

