# include <stdio.h> // perror(), printf()
# include <stdlib.h> // exit()
# include <fcntl.h> // open(), read()
# include <unistd.h> // read()

int	main(void)
{
	int		fd;
	int		sz;
	char	c[100];

	fd = open("foo.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("r1");
		exit (1);
	}
	sz = read(fd, c, 99);
	printf("Called read(%d, c, 99). returned that"
			" %d bytes were read.\n", fd, sz);
	c[sz] = '\0';
	printf("Those bytes are as follows: %s\n", c);
	return (0);
}
