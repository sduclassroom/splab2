// your code here
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int x1=atoi(argv[1]);
    int x2=atoi(argv[2]);

    
    int pid=fork();   
   
    if(pid < 0){
        exit(1);
    }else if( pid == 0){

        printf ("child:1 %d + %d = % d  \n ", x1, x2, x1+x2);  
    }else{
        int pid1 =fork ();
        if (pid1 < 0){
            exit(1);
        }else if(pid1==0){
            printf ("child:2 %d - %d = % d  \n ", x1, x2, x1-x2);  
        }else{
            int pid2 =fork ();
            if ( pid2 < 0){
                exit(1);
            }else if(pid2==0){
                printf ("child:3 %d * %d = % d  \n ", x1, x2, x1*x2);
            }else {
                int pid3 =fork ();
                if ( pid3 < 0) {
                    exit(1);
                }else if(pid3==0){
                    printf ("child:4 %d / %d = % d  \n ", x1, x2, x1/x2);
                }else{
                    wait(0);
                    wait(0);
                    wait(0);
                    wait(0);
                printf ("parent done\n");
            }}}}
}
