#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
static int count = 0;
typedef void (*sighandler_t)(int);
void sig_handler(int signo);
int main(int argc, char **argv){
	int i=0;
	signal(SIGTSTP,(void *)sig_handler);
	while(1){
		printf("%d \n", i);
		i++;
		sleep(1);
	}
	return 0;
}
void sig_handler(int signo){
	count++;
	if(count == 1){
		printf("\nnostop\n");
	}
	else {
		printf("SIGINT %d\n", SIGINT);
		kill(getpid(), SIGSTOP);
	}
}
