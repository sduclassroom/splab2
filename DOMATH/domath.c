// your code here
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
	int argument1 = atoi(argv[1]);
	int argument2 = atoi(argv[2]);
	for (int i=0;i<4;i++){
		int rc = fork();
	    if (rc == 0){
        if (i==0){
		 printf("child1: %d+%d=%d\n",argument1,argument2,argument1+argument2);
		}
		else if(i==1){
		printf("child2: %d-%d=%d\n",argument1,argument2,argument1-argument2);
		}
		else if (i==2){
		printf("child3: %d-%d=%d\n",argument1,argument2,argument1*argument2);
		}
		else if (i==3){
		printf("child4: %d/%d=%d\n",argument1,argument2,argument1/argument2);
		}
        exit(0);}
        	else{
        		wait(NULL);
        }
	

    	
	
    	
}
printf("parent: done\n");
}


