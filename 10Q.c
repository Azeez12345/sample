#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        int a;
        a = open("temp.txt",O_RDWR | O_CREAT);
        if(a == -1)
        {
                printf("Error!\n");
        }
        int c;
	char* buffer=(char*)calloc(100,sizeof(char));
        read(a,buffer,5);
	printf("%s\n",buffer);
	printf("%d\n",SEEK_CUR);
        int seek = lseek(a,5,SEEK_CUR);
        read(a,buffer,5);
	printf("%s\n",buffer);
        return 0;
}
