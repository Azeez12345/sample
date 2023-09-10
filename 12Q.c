#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>

int main(){
	int a =open ("curr.txt", O_RDONLY|O_CREAT);
	int flag;
	flag=fcntl(a, F_GETFL);
	if(flag==-1)
	{
		perror("fcntl");
		exit(1);
	}
	switch(O_ACCMODE & flag)
	{
		case 0:
			printf("The file has been opened with the flags : O_RDONLY\n");				break;
		case 1:
                    printf("The file has been opened with the flags : O_WRONLY\n");
                    break;
                case 2:
                    printf("The file has been opened with the flags : O_RDWR\n");
                    break;
                // Any of the below cases will never be invoked
                case 64:
                    printf("The file has been opened with the flags : O_CREAT\n");
                    break;
                case 512:
                    printf("The file has been opened with the flags : O_TRUNC\n");
                    break;
                case 1024:
                    printf("The file has been opened with the flags : O_APPEND\n");
                    break;
                case 577:
                    printf("The file has been opened with the flags : O_WRONLY | O_CREAT | O_TRUNC\n");
                    break;
                case 1089:
                    printf("The file has been opened with the flags : O_WRONLY | O_CREAT | O_APPEND\n");
                    break;
                case 578:
                    printf("The file has been opened with the flags : O_RDWR   | O_CREAT | O_TRUNC\n");
                    break;
                case 1090:
                    printf("The file has been opened with the flags : O_RDWR   | O_CREAT | O_APPEND\n");
                    break;
                default:
                    printf("Error!");
	}
	
	return 0;
}
