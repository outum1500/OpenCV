#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
	int old;
	old=umask(0);
	printf("old = 0%o\n", old); 
	old = umask(old); 
	printf("new umask = 0%o\n", old);
	return 0;
}
