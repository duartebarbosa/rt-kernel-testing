// header test for miavita project - preemptive rt-kernel - duarte.barbosa

#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]){

	struct timespec resolution;
	
	clock_getres(CLOCK_REALTIME, &resolution);
	
	printf("-------\nSleep time: %ld nanoseconds.\n", ((atol(argv[1])) * 1000000000 + atol(argv[2])));
	printf("Resolution: %ld nanoseconds.\n", (resolution.tv_sec * 1000000000 + resolution.tv_nsec));
	
	return 0;
}
