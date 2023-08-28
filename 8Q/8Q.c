

#include<stdio.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
const char EOL = '\n';

int main() {
  FILE* a=fopen("temp.txt", "r");
  if(a == NULL) {
    printf("Error %d", errno);
    perror("Program");
    exit(0);
  }
  int b=fgetc(a);
  char buffer[1024];
  int i=0;
  while(b!=EOF) {
    while(b!=EOL) {
      printf("%c", b);
      buffer[i]=b;
      //write(1, b, 10);
      i++;
      b=fgetc(a);
    }
    buffer[i++]='\n';
    write(1, buffer, i);
    buffer[0]='\0';
    b=fgetc(a);
    i=0;
  }
  fclose(a);
  return 0;
}


