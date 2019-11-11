// your code here
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main (int argc, char *argn[]){
    int status;
    int x,y;
    if(argc!=3) {
        printf("incorrect number of arguments \n");
        exit(EXIT_FAILURE);
    }

    x=atoi(argn[1]);
    y=atoi(argn[2]);
    
    
    if (fork() == 0){   

        printf("child 1: %d+%d=%d\n", x, y, x+y);
        exit(EXIT_SUCCESS);
    }

    
    if (fork() == 0){   

        printf("child 2: %d-%d=%d\n", x, y, x-y);
        exit(EXIT_SUCCESS);
    }
    
    
    if (fork() == 0){   

        printf("child 3: %d*%d=%d\n", x, y, x*y);
        exit(EXIT_SUCCESS);
    }
    
    
    if (fork() == 0){   

        printf("child 4: %d/%d=%d\n", x, y, x/y);
        exit(EXIT_SUCCESS);
    }

    int i;
     for (i = 0; i < 3; ++i){
        wait(&status);
    }

    printf("parent: done. \n");
    exit(EXIT_SUCCESS);
}
