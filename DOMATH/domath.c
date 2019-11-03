#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void executeFor(int x, int y);

void systemCustom(int childCount, int x, int y) {
    pid_t pid = fork();
    if (pid == 0){
        switch (childCount) {
            case 1:
                printf("child%d: %d + %d = %d\n",childCount, x, y, x+y);
                break;
            case 2:
                printf("child%d: %d - %d = %d\n",childCount, x, y, x-y);
                break;
            case 3:
                printf("child%d: %d * %d = %d\n",childCount, x, y, x*y);
                break;
            case 4:
                printf("child%d: %d / %d = %d\n",childCount, x, y, x/y);
                break;
            default:
                break;
        }
        exit(-1);
    } else {
        waitpid(pid, 0, 0);
    }
}

int main(int argc, char *argv[]){
    char *p;
    if (argc > 2) {
        int x = strtol(argv[1], &p, 10);
        int y = strtol(argv[2], &p, 10);
        
        pid_t pid = fork();
        
        if (pid == 0) {
            for( int i = 1; i <= 4; i++) { 
                systemCustom(i, x, y);
            }
        } else {
            waitpid(pid, 0, 0);
            printf("parent: done.");
        }
    }
    return 0;
}
