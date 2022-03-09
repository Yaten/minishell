# include <unistd.h> // unlink()
# include <stdio.h> // printf()

int	main(int argc, char *argv[])
{
	if (argc < 2)
		printf("Usage: %s [file to delete]\n", argv[0]);
	else
		unlink(argv[1]);
	return (0);
}
