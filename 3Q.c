#include<stdio.h>
#include<fcntl.h>

int main() {
  char* filenm="curr1.txt";
  mode_t md=S_IRUSR;
  int a;
  if((a=creat(filenm, md))<0)
    perror("Error creating file");
  else
    printf("Creation Successfull! %d", a);
}
