# include <stdio.h> // printf()
# include <errno.h> // errno
# include <string.h> // stderror()
# include <fcntl.h> // open()

int	main(void)
{
	int	fd;

	// if a file is opened which does not exist, then it will be an error
	// and corresponding errno value will be set
	fd = open("willian.txt", O_RDONLY);
	printf("Value of errno: %d\n", errno);
	printf("The error message is: %s\n", strerror(errno));
	perror("Message from perror");
	return (0);
}
