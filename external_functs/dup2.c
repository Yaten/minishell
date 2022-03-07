# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>


int	main(void)
{
	int	file_desc;

	file_desc = open("tricky.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);
	// here the newfd is the file descriptor of stdout (i.e. 1)
	dup2(file_desc, 1);
	// all the print statements will be written in the file
	// "tricky.txt"
	printf("I will be printed in the file tricky.txt\n");
	return (0);
}
