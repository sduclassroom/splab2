#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h> 
#include <stdarg.h>  
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
		char string[100];
		strcpy(string, "java MathDoAddition ");
 		strcat(string, argv[1]);
		strcat(string, " ");
 		strcat(string, argv[2]);
		pid_t proc = fork();

		if(proc < 0){
			abort();
		}

		else if(proc == 0){
			char *name[] = { "/bin/bash","-c",string,NULL};
			execvp(name[0], name);
			exit(-1);
		}

		else{
			waitpid(proc,0,0);
				
		}
		

	}
	else if(pids[1]==pid){
		char string[100];
		strcpy(string, "python MathDoSubstraction.py ");
 		strcat(string, argv[1]);
		strcat(string, " ");
 		strcat(string, argv[2]);

		pid_t proc = fork();

		if(proc < 0){
			abort();
		}

		else if(proc == 0){
			char *name[] = { "/bin/bash","-c",string,NULL};
			execvp(name[0], name);
			exit(-1);
		}

		else{
			waitpid(proc,0,0);
				
		}
		
	}
	else if(pids[2]==pid){
    		char string[100];
		strcpy(string, "./MathDoMultiply ");
 		strcat(string, argv[1]);
		strcat(string, " ");
 		strcat(string, argv[2]);

		pid_t proc = fork();

		if(proc < 0){
			abort();
		}

		else if(proc == 0){
			char *name[] = { "/bin/bash","-c",string,NULL};
			execvp(name[0], name);
			exit(-1);
		}

		else{
			waitpid(proc,0,0);
				
		}

	}
	else if(pids[3]==pid){
		char string[100];
		strcpy(string, "python MathDoDeleting.py ");
 		strcat(string, argv[1]);
		strcat(string, " ");
 		strcat(string, argv[2]);

		pid_t proc = fork();

		if(proc < 0){
			abort();
		}

		else if(proc == 0){
			char *name[] = { "/bin/bash","-c",string,NULL};
			execvp(name[0], name);
			exit(-1);
		}

		else{
			waitpid(proc,0,0);
				
		}
	}
		
  --n;  
}
}

}

