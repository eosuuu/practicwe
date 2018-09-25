#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int fd1 = 0, fd2 =0;
	char buf[5+1] ="";

	if(argc != 2)
	{
		fprintf(stderr, "ERROR the number of parameters : %s <file name>\n", argv[0]);
		return 1;
	}
	
	fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1)
	{
		fprintf(stderr, "Fail to open %s\n", argv[1]);
		return 1;
	}

	fd2 = dup(fd1);
	if(fd2 == -1)
	{
		perror("Fail to us 'dub' fuction\n");
		return 1;
	}
		
	read(fd1, buf, 5);
	printf("File descripter : fd1 = %s\n", buf);
	close(fd1);
		
	read(fd2, buf, 5);
	printf("File descripter : fd2 = %s\n", buf);
	close(fd2);
		
	return 0;
}
	
