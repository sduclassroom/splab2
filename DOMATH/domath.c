// your code here
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]){
    
	int a = atoi(argv[1]);	
	int b = atoi(argv[2]);	
	
	pid_t p1 = fork();
	
	if (p1 == 0) {
		printf("ch1: %d + %d = %d \n", a, b, a + b);
		exit(0);
	}    
	pid_t p2 = fork();
	
	if (p2 == 0) {
		printf("ch2: %d * %d = %d \n", a, b, a * b);
		exit(0);
	} 
	pid_t p3 = fork();

	if (p3 == 0) {
		printf("ch3: %d - %d = %d \n", a, b, a - b);
		exit(0);
	}    

	pid_t p4 = fork();
	
	if (p4 == 0) {
		printf("ch4: %d / %d = %d \n", a, b, a / b);
		exit(0);
	} 
    	waitpid(p1, NULL, 0);
    	waitpid(p2, NULL, 0);
    	waitpid(p3, NULL, 0);
    	waitpid(p4, NULL, 0);

	printf("parent: done.\n");

}
