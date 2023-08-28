#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

void tempfile(char const fileName[]);
char *formatdata(char * str , time_t val);
int main()
{
	ssize_t rd;
	char* buf = 0;
	size_t bufsize = 0;

	printf("Enter name of the file: \n");
	rd = getline(&buf,&bufsize,stdin);

	if(rd <=0 ){
		printf("getline failed\n");
		exit(1);
	}

	if(buf[rd-1] == '\n'){
		buf[rd-1] = 0;
	}

	int a = open(buf,O_RDONLY);
	if(a==-1){
		printf("File doesn't exist\n");
		exit(1);
	}
	else
	{
		tempfile(buf);
	}
	free(buf);
	return 0;
}

char * format(char *str1, time_t val1){
	strftime(str1,36,"%d.%m.%Y %H:%M:%S",localtime(&val1));
	return str1;
}

void tempfile(char const fileName[]){
	struct stat tempfile;
	if(stat(fileName,&tempfile)==-1){
		printf("Error Occured\n");
	}

	char date[36];
	printf("\ninode no : %ld",tempfile.st_ino);
	printf("\nNo of hard links: %d",(unsigned int)tempfile.st_nlink);
	printf("\nUID : %d",tempfile.st_uid);
	printf("\nGID : %d",tempfile.st_gid);
	printf("\nSize : %ld",tempfile.st_size);
	printf("\nBlock size : %ld",tempfile.st_blksize);
	printf("\nNumber of blocks : %ld",tempfile.st_blocks);
	printf("\nTime of last acces : %s",format(date,tempfile.st_atime));
	printf("\nTime of last modification : %s",format(date,tempfile.st_ctime));
	printf("\nTime of last change : %s",format(date,tempfile.st_mtime));
	printf("\n");
}
