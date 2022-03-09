# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define MSGSIZE 16

// int	main(void)
// {
// 	char	msg1[16] = "hello, world #1";
// 	char	msg2[16] = "hello, world #2";
// 	char	msg3[16] = "hello, world #3";
// 	char	inbuf[MSGSIZE];
// 	int		p[2];
// 	int		i;

// 	if (pipe(p) < 0)
// 		exit(1);
// 	write(p[1], msg1, MSGSIZE);
// 	write(p[1], msg2, MSGSIZE);
// 	write(p[1], msg3, MSGSIZE);
// 	i = -1;
// 	while (++i < 3)
// 	{
// 		read(p[0], inbuf, MSGSIZE);
// 		printf("%s\n", inbuf);
// 	}
// 	return (0);
// }

int	main(void)
{
	char	msg1[16] = "Hello, world #1";
	char	msg2[16] = "Hello, world #2";
	char	msg3[16] = "Hello, world #3";
	char	inbuf[MSGSIZE];
	int		p[2];
	int		pid;
	int		nbytes;

	if (pipe(p) < 0)
		exit (1);
	if ((pid = fork()) > 0)
	{
		write(p[1], msg1, MSGSIZE);
		write(p[1], msg2, MSGSIZE);
		write(p[1], msg3, MSGSIZE);
		wait(NULL);
	}
	else
	{
		while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0)
			printf("%s\n", inbuf);
		if (nbytes != 0)
			exit (2);
		printf("Finished reading\n");
	}
	return (0);
}










