# include <stdio.h>
# include <fcntl.h> // lib for close();
# include <unistd.h>
# include <stdlib.h>

int	main(void)
{
	int	fd1;

	fd1 = open("foo.txt", O_RDONLY);
	if (fd1 < 0)
	{
		perror("c1");
		exit(1);
	}
	printf("opened the fd = %d\n", fd1);
	// using close system call
	if (close(fd1) < 0)
	{
		perror("c1");
		exit();
	}
	printf("Closed the fd.\n");
	return (0);
}
