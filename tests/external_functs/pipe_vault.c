# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int	main(int argc, const char *argv[])
{
	int	fd[2];
	int	id;
	int	x;
	int	y;

	if (pipe(fd) == -1)
	{
		printf("An error ocurred with opening the pipe\n");
		return (1);
	}
	id = fork();
	if (id == -1)
	{
		printf("An error ocurred with fork\n");
		return (4);
	}
	if (id == 0)
	{
		close(fd[0]);
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("An error ocurred with writing to the pipe\n");
			return (2);
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("An error ocurred with reading from the pipe\n");
			return (3);
		}
		y *= 3;
		close(fd[0]);
		printf("Got from child process %d\n", y);
	}
	return (0);
}
