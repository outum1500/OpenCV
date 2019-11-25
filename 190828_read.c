#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	int fd;
	int buf_size=10;
	int read_count;
	char buf[10];
	fd=open("./test.txt", O_CREAT|O_RDWR, 0666);
	read_count=read(fd,buf,buf_size);
	printf("bufsize = %d, read_count = %d\n", buf_size, read_count);
	printf("read data = %s\n", buf);
	return 0;
}
