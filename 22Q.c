#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<fcntl.h>

void main()
{
	FILE* fd = fopen("exmpl.txt","a");
	int f = fork();
	if(f>0)
	{
		fprintf(fd,"Parent id: %d\n",getpid());
	}
	else if(f == 0)
	{
		fprintf(fd,"Child id: %d\n",getpid());
	}
	fclose(fd);
}
