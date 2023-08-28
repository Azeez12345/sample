#include<stdio.h>
#include<fcntl.h>
#include<stdbool.h>

int main() {
  int a = 0;
  FILE* fl;
  while (true) {
    if(a<5) {
      char buffer[32];
      snprintf(buffer, sizeof(char) * 32, "fl%i.txt", a);
      fl = fopen(buffer, "wb");
      fclose(fl);
      a++;
    }
  }
  return 0;
}
