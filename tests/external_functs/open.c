# include <stdio.h>
# include <fcntl.h> // lib for open();
# include <errno.h>

extern int errno;

int	main(void)
{
	// if file does not have in directory
	// then file foo.txt is created
	int	fd;

	fd = open("foo.txt", O_RDONLY | O_CREAT);
	printf("fd = %d\n", fd);
	if (fd == -1)
	{
		// print which type of error have in a code
		printf("Error Number %d\n", errno);
		// print program detail "Success or failure"
		perror("program");
	}
	return (0);
}
