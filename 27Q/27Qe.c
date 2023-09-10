
#include <unistd.h> 
#include <stdio.h>  

void main()
{
    
    char *args[] = {"/bin/ls", "-Rl", NULL};
    execvp(args[0], args);
    printf("\n");
}
