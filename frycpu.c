#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define PROCESSES 6
#define MAX_ITERATIONS 100000

int main(){

	int register i = 0, pid, initial, j = 0;
	void * memptr = NULL;

	initial = (int) getpid();
	
	for(; i < PROCESSES; i++){
		pid = fork();
	}
	
	for(i = 1; i < MAX_ITERATIONS;i++){
		memptr = malloc(i);
		i = i%2;
		if(memptr != NULL)
			free(memptr);
	}
	
//	printf("%d - processo #%d\n", (j = j + 1), (pid - initial));
	return 0;
}
