#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
    pid_t pids[4];
int i;
int n = 4;

/* Start children. */
for (i = 0; i < n; ++i) {
  if ((pids[i] = fork()) < 0) {
    perror("fork");
    abort();
  } else if (pids[i] == 0) {
    
    exit(0);
  }
}

/* Wait for children to exit. */

pid_t pid;

if (argc == 3){
int x;
int y;
sscanf (argv[1],"%d",&x);
sscanf (argv[2],"%d",&y);

while (n > 0) {
  	pid = wait(NULL);

	if(pids[0]==pid){
		printf("%d + %d = %d\n",x,y,x+y);
	}
	else if(pids[1]==pid){
		printf("%d - %d = %d\n",x,y,x-y);
	}
	else if(pids[2]==pid){
		printf("%d * %d = %d\n",x,y,x*y);
	}
	else if(pids[3]==pid){
		printf("%d / %d = %d\n",x,y,x/y);
	}
		
  --n;  
}
}
}
