# include <stdio.h>
# include <unistd.h> // dup()
# include <fcntl.h>

int	main(void)
{
	int	file_desc;
	int	copy_desc;

	file_desc = open("dup.txt", O_WRONLY | O_APPEND | O_CREAT, 0666);
	if (file_desc < 0)
		printf("Error opening the file\n");
	copy_desc = dup(file_desc);
	write(copy_desc, "This will be output to the file named dup.txt\n", 46);
	write(file_desc, "The will also be output to the file named dup.txt\n", 51);
	return (0);
}
