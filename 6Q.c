 #include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(void){
int fd;
char buf[80];

fd= open("result", O_WRONLY | O_CREAT);
read(0,buf,sizeof(buf));
write(1, buf, sizeof(buf));
printf("%s\n", buf);
}
