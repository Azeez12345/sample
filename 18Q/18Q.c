#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

struct players{
  int jersey_no;
  char name[20];
  int score;
};

int main() {
  struct flock lock;
  int fd=open("playerstats.txt", O_CREAT | O_RDWR, 0744);
  struct players pla1, pla2, pla3;
  pla1.jersey_no=1;
  pla2.jersey_no=2;
  pla3.jersey_no=3;
  strcpy(pla1.name, "Messi");
  strcpy(pla2.name, "Ronaldo");
  strcpy(pla3.name, "Neymar");
  pla1.score=810;
  pla2.score=820;
  pla3.score=500;
  write(fd, &pla1, sizeof(struct players));
  lock.l_type=F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 8;
  lock.l_len = 8;
  lock.l_pid = getpid();
  fcntl(fd,F_SETLKW , &lock);
  printf("Entered critical section...\n");
  printf("Press return to unlock...\n");
  getchar();
  printf("Write lock unset...\n");
  lock.l_type=F_RDLCK;
  lock.l_start=0;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Read lock set...\n");
  lock.l_type=F_UNLCK;
  lock.l_start=8;
  lock.l_len=8;
  fcntl(fd, F_SETLKW, &lock);
  printf("Press return to exit...\n");
  getchar();
  printf("Read lock unset...\n");
  close(fd);
  return 0;
}
