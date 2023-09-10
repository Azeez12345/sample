 #include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(void){
char buf[80];
int n = read(0,buf,sizeof(buf));
write(1, buf, n);
printf("%s\n", buf);
}
