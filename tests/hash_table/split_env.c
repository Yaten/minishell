# include "../../ft_printf/libft/libft.h"
# include <stdio.h>

int	main(int argc, char *argv[], char *envp[])
{
	int		j;
	char	*last;
	char	*tmp1;
	char	*before;

	j = -1;
	while (envp[++j])
	{
		tmp1 = ft_strchr(envp[j], '=');
		before = ft_substr(envp[j], 0, tmp1 - envp[j]);
		last = ft_substr(envp[j], tmp1 + 1 - envp[j], ft_strlen(envp[j]));
		printf("Antes: %s\n", before);
		printf("Depois: %s\n", last);
		free (before);
		free (last);
	}
	return (0);
}
