#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>

int main(){
	int a =open ("curr.txt", O_RDONLY);
	int flag,Acmd;
	flag=fcntl(a, F_GETFL);
	if(flag==-1)
		exit(1);
	printf("opening mode %d \n", flag);
	return 0;
}
