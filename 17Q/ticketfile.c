#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main() {
  struct flock lock;
  int fd=open("result.txt", O_RDWR);
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 0;
  int buffer;
  lock.l_type=F_RDLCK;
  printf("Read lock set\n");
  fcntl(fd, F_SETLKW, &lock);
  read(fd, &buffer, sizeof(int));
  lseek(fd, -4, SEEK_CUR);
  printf("Read ticket no: %d\n", buffer);
  buffer++;
  lock.l_type=F_WRLCK;
  fcntl(fd, F_SETLKW, &lock);
  printf("Write lock set\n");
  write(fd, &buffer, sizeof(int));
  lseek(fd, -4, SEEK_CUR);
  read(fd, &buffer, sizeof(int));
  printf("Read after writing: %d\n", buffer);
  printf("Press return to unlock...");
  getchar();
  lock.l_type=F_UNLCK;
  fcntl(fd, F_SETLKW, &lock);
  close(fd);
  return 0;
}
