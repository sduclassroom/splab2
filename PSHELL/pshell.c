
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h> 
#include <stdarg.h>   
#include <stdio.h>
#define MAX_SIZE 1025

int print_select(); 
pid_t child_pids[1000];
int child_nb=0;


int main() 
{
	char str[MAX_SIZE];  /* Initialize static memory. */
    int length;
	char str_copy[MAX_SIZE];
	printf("Enter a command line ");
    while (fgets( str, MAX_SIZE, stdin))
    {
	
	
	
        length=strlen(str);
       
        if (str[length-1]=='\n')
        {
             str[length-1]='\0';
        }


	int x=0,z=length;
	 while (str[x]==' ')
        	x++;
    	while (str[z-1]==' ')
        	z--;
	z-=x;
	strncpy(str,str+x,z);
	

	length=strlen(str);	
       	if(strcmp(str,"exit")==0){
		exit(1);
		break;
	}
	else if(strcmp(str,"showjobss")==0){
		for(int i=0;i < (child_nb+1);i++){
			printf("%ld\n",(long)child_pids[i]);
		}
	}
	else{
		char *pChar = &str[strlen(str)-1];
		if(strcmp(pChar,"&")==0){
			
			pid_t process = fork();

			if(process<0){
				abort();
			}
			else if(process==0){
				char *name[] = { "/bin/bash","-c",str,NULL};
				execvp(name[0], name);
				exit(-1);
		
			}

			else{ 
				waitpid(process,0,0);
			}

			child_pids[child_nb++] = process;
				
		}
		
		else{
			pid_t process=fork();
			if(process<0){
				abort();
			}
			else if(process==0){
				  char *name[] = { "/bin/bash","-c",str,NULL};
				  execvp(name[0], name);
				exit(-1);
			}

			else{
				waitpid(process,0,0);
				
			}
							
		}
	}
	
	printf("Enter a command line ");
    }
    return 0; 
 
	

} 





