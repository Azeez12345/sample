#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main() {
  int a=open("curr12.txt", O_RDWR | O_CREAT | O_EXCL, 0777);

  if(a == -1) {
    printf("Error %d\n", errno);
    perror("Program");
  }
  printf("a=%d \n", a);
  char* str="Test line.";
  int writing=write(a, str, strlen(str)+1);
  printf("Status of writing : %d\n", writing);
  close(a);
  a=open("curr.txt", O_RDWR);
  char str2[80];
  read(a, str2, 80);
  printf("Read = %s\n", str2);
  close(a);
}

