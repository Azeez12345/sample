#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/select.h>

int main() {
  fd_set readfds;
  struct timeval timeout;
  FD_ZERO(&readfds);
  FD_SET(0, &readfds);
  timeout.tv_sec=10;
  timeout.tv_usec=0;
  int rselect=select(1, &readfds, NULL, NULL, &timeout);
  if(rselect < 0) {
    perror("select");
    exit(1);
  } else if(rselect == 0) {
    printf("Data not available\n");
    exit(1);
  } else if(rselect > 0) {
    printf("Data available\n");
    exit(1);
  }
  return 0;
}
