#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
	int fd;
	fd = open("./test.txt", O_WRONLY|O_CREAT|O_TRUNC, 0740);

	printf("%d\n", fd);
}
