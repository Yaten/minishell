# include <unistd.h>

// int	main(int argc, char *argv[])
// {
// 	int	j;

// 	j = -1;
// 	while (++j < argc)
// 		printf("argv[%d]: %s\n", j, argv[j]);
// 	exit (EXIT_SUCCESS);
// }

int	main(int argc, char *argv[])
{
	char	*newargv[] = {"ls" , "NULL"};
	char	*newenviron[] = {NULL};

	execve("/usr/bin/ls" , newargv, newenviron);
	return (0);
}
