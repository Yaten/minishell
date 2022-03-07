# include <stdio.h> // printf()
# include <unistd.h> // fork()

int	main(int argc, char *argv[])
{
	int	id;

	id = fork();
	// printf("Hello world from id: %d\n", id);
	if (id == 0)
		printf("Hello from child process\n");
	else
		printf("Hello from the main process\n");
	return (0);
}
