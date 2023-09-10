#include<stdio.h>
#include<sched.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	pid = getpid();
	int p = sched_getscheduler(pid);
	if(p == -1)
	{
		perror("sched_getscheduler");
		return 1;
	}
	printf("Scheduler policy is: \n");
	switch(p)
	{
		case SCHED_OTHER:
			printf("SCHED_OTHER\n");
			break;
		case SCHED_FIFO:
		       	printf("SCHED_FIFO\n");
	       		break;
		case SCHED_RR:
			printf("SCHED_RR\n");
			break;
		default:
			printf("UNknown\n");
			break;
	}
	struct sched_param new_param;
	new_param.sched_priority = 50;
	int np = SCHED_FIFO;
	int set_policy = sched_setscheduler(pid,np,&new_param);
	if(set_policy == -1)
	{
		perror("sched_setscheduler");
		return 1;
	}
	int up = sched_getscheduler(pid);
	 if(up == -1)
        {
                perror("sched_getscheduler");
                return 1;
        }
        printf("Scheduler policy is: \n");
        switch(up)
        {
                case SCHED_OTHER:
                        printf("SCHED_OTHER\n");
                        break;
                case SCHED_FIFO:
                        printf("SCHED_FIFO\n");
                        break;
                case SCHED_RR:
                        printf("SCHED_RR\n");           
                        break;
                default:
                        printf("UNknown\n");
                        break;
        }
	return 0;
}

	


