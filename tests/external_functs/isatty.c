# include <stdlib.h> // needed for exit()
# include <unistd.h> // needed for isatty()
# include <stdio.h> // needed for printf()

int	main(int argc, char *argv[])
{
	if (isatty(0))
		printf("The standard input is from a terminal\n");
	else
		printf("The standard input is NOT from a terminal\n");
	if (isatty(1))
		printf("The standard output is to a temrinal\n");
	else
		printf("The standard output is NOT to a terminal\n");
	return (0);
}
