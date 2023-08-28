#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>

int main() {
  int original_fd=open("file_1", O_RDWR | O_CREAT, 0666);
  int dup_fd=dup(original_fd);
  char buf[]="file_1: This is written by original_fd\n";
  write(original_fd, buf, sizeof(buf));
  (void)strncpy(buf, "This is written by dup_fd\n", sizeof(buf));
  write(dup_fd, buf, sizeof(buf));
  close(original_fd);
  original_fd=open("file_2", O_RDWR | O_CREAT, 0666);
  dup_fd=fcntl(original_fd, F_DUPFD);
  (void)strncpy(buf, "file_2: This is written by original_fd\n", sizeof(buf));
  write(original_fd, buf, sizeof(buf));
  (void)strncpy(buf, "This is written by dup_fd-f\n", sizeof(buf));
  write(dup_fd, buf, sizeof(buf));
  close(original_fd);
  original_fd=open("file_3", O_RDWR | O_CREAT, 0666);
  dup2(original_fd, 1);
  printf("file_2: This is written by dup2\n");
  close(original_fd);
  return 0;
}
