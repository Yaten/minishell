# include <stdio.h>
# include <unistd.h>

int	main(void)
{
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");
	else
		printf("Current working directory is: %s\n", cwd);
	return (0);
}
