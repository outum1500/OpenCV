#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd;
	int buf_size=32;
	int write_count;
	char buf[32];
	fd = open("./test.txt", O_CREAT|O_RDWR);
	printf("input message \n");
	scanf("%[^\n]s", buf);
	buf_size = strlen(buf);
	write_count = write(fd, buf, buf_size);
	printf("write data=%s\n");
	return 0;
}
