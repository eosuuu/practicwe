#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	int fd = 0; 
	
	if(argc != 2)
	{
		fprintf(stderr, "Error, Execution as follows: %s <filename>\n", argv[0]);
		return 1;
	}
	
	fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0777);
	
	if(fd == -1)
	{
		fprintf(stderr, "Fail to open %s\n", argv[1]);
		return 1;
	}
	
	if(lseek(fd, 20, SEEK_CUR) == -1)
	{
		printf("Don't be able to use lseek about the %s file. \n", argv[1]);
	}
	else
	{	
		char insert = 'a';
		write(fd, &insert, 1);
	}
	
	close(fd);
	return 0;
}

