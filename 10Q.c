#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        int a;
        a = open("temp12.txt",O_RDWR | O_CREAT, 0777);
        if(a == -1)
        {
                printf("Error!\n");
        }
        write(a,"1234567890",10);
	lseek(a,10,SEEK_CUR);
	write(a,"abcdefghij",10);
	int s = lseek(a,0,SEEK_CUR);
	printf("%d\n",s);

	close(a);
	return 0;
}
