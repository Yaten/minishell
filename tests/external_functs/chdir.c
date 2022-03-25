# include <stdio.h>
# include <unistd.h>

//############################# EXAMPLE 1 #############################

// int	main(void)
// {
// 	char	s[100];

// 	printf("%s\n", getcwd(s, 100));
// 	chdir("..");
// 	printf("%s\n", getcwd(s, 100));
// 	return (0);
// }

//############################# EXAMPLE 2 #############################

int	main(void)
{
	char	s[100];

	printf("%s\n", getcwd(s, 100));
	if (chdir("/usr") != 0)
		perror("chdir() to /usr failed");
	printf("%s\n", getcwd(s, 100));
	// if (chdir("/tmp") != 0)
	// 	perror("chdir() to /temp failed");
	// printf("%s\n", getcwd(s, 100));
	// if (chdir("/error") != 0)
	// 	perror("chdir() to /error failed");
	return (0);
}
