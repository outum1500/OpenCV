#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
void sig_handler(int signo);
int main(int argc, char **argv){
	int i=0;
	signal(SIGINT,(void *)sig_handler);
	while(1){
		printf("%d \n", i);
		i++;
		sleep(1);
	}
	return 0;
}
void sig_handler(int signo){
	printf("SIGINT %d\n", SIGINT);
	kill(getpid(), SIGQUIT);
}
