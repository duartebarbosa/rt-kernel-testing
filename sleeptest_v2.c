// test v2 - moded for miavita project - preemptive rt-kernel - duarte.barbosa

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define ITERATIONS 5

int main(int argc, char *argv[]){

	struct timespec *sleepy = (struct timespec *) malloc(sizeof(struct timespec)), start, stop;
  	sleepy->tv_sec = atoi(argv[1]);
	sleepy->tv_nsec = atoi(argv[2]);
	register int i = ITERATIONS;
	
	clock_gettime(CLOCK_REALTIME, &start);
 
	while(i--)
		nanosleep(sleepy, NULL);

	clock_gettime(CLOCK_REALTIME, &stop);
	printf("Elapsed Time: %ld nanoseconds.\n", ((stop.tv_sec * 1000000000 + stop.tv_nsec) - (start.tv_sec * 1000000000 +  start.tv_nsec))/ITERATIONS);
	
	return 0;
}
