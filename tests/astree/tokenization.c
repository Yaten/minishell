#include <stdio.h>
#include <ctype.h>

int	main(int argc, char *argv[])
{
	char	*inputs = argv[1];
	char	*input[50];
	char	buffer[50];
	int		i;
	int		strnum = 0;
	char	*next = buffer;
	char	c;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s expression\n", argv[0]);
		return (1);
	}
	printf("input: <<%s>>\n", inputs);
	printf("parsing:\n");
	while ((c = *inputs++) != '\0')
	{
		input[strnum++] = next;
		if (isdigit(c))
		{
			printf("Digit: %c\n", c);
			*next++ = c;
			while (isdigit(*inputs))
			{
				c = *inputs++;
				printf("Digit: %c\n", c);
				*next++ = c;
			}
			*next++ = '\0';
		}
		else
		{
			printf("Non-digit: %c\n", c);
			*next++ = c;
			*next++ = '\0';
		}
	}
	printf("parsed:\n");
	i = -1;
	while (++i < strnum)
		printf("%d: <<%s>>\n", i, input[i]);
	return (0);
}










