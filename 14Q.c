#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
	if(argc !=2){
		printf("usage: %s <filename>\n", argv[0]);
		return 1;
	}

	const char* filenm=argv[1];

	struct stat file_stat;
	if(stat(filenm, &file_stat)==-1){
		perror("Cannot get file information");
		return 1;
	}

	if(S_ISREG(file_stat.st_mode)){
		printf("%s Regular File. \n", filenm);
	}
	else if (S_ISDIR(file_stat.st_mode)){
		printf("%s Directory.\n", filenm);
	}
	else if(S_ISLNK(file_stat.st_mode)){
		printf("%s Symbol Link.\n", filenm);
	}
	else if(S_ISFIFO(file_stat.st_mode)){
		printf("%s FIFO or PIPE.\n", filenm);
	}
	else if(S_ISSOCK(file_stat.st_mode)){
		printf("%s Socket.\n", filenm);
	}
	else if(S_ISBLK(file_stat.st_mode)){
		printf("%s Block special file.\n" , filenm);
	}
	else if(S_ISCHR(file_stat.st_mode)){
		printf("%s Character Special file.\n" , filenm);
	}
	else{
		printf("%s Unknown\n" , filenm);
	}
	return 0;
}

