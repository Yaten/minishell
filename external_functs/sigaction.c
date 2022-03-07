# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	handler(int num)
{
	write (STDOUT_FILENO, "I won't die!\n", 14);
}

int	main(void)
{
	signal(SIGINT, handler);
	while (1)
	{
		printf("Wasting your cycles. %d\n", getpid());
		sleep(1);
	}
	return (0);
}
