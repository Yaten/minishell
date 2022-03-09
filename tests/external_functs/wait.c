# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/wait.h>

// int	main(void)
// {
// 	if (fork() == 0)
// 		printf("HC: hello from child\n");
// 	else
// 	{
// 		printf("HP: hello from parent\n");
// 		wait(NULL);
// 		printf("CT: child has terminated\n");
// 	}
// 	puts("Bye ");
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	int	id;
	int	n;
	int	i;

	id = fork();
	if (id == 0)
		n = 1;
	else
	{
		wait (NULL);
		n = 6;
	}
	i = n;
	while (i < n + 50)
	{
		printf("%d ", i);
		fflush(stdout);
		i++;
	}
	puts("");
	return (0);
}
