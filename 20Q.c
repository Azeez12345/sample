#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>
int main()
{
	pid_t pid = getpid();
	int priority = getpriority(PRIO_PROCESS, pid);
	printf("nice value of my process is - %d",priority);
	sleep(30);
	nice(10);
	priority = getpriority(PRIO_PROCESS, pid);
	printf("nice value of my process is - %d",priority);
	sleep(20);
	return 0;
}
