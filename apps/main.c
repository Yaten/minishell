/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/09 18:54:51 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_minishell.h"
# include <stdio.h>




void fill_prompt(t_prompt *prompt)
{
	prompt->user = getenv("USER");
	prompt->hostname = getenv("NAME");
	prompt->path = getenv("PWD");
}

char *find_path(char *abs_path)
{
	int i;
	char *pointer;

	i = -1;
	
	pointer = abs_path + 1;
	while (++i < 2)
	{
		pointer = ft_strchr(pointer, '/');
		pointer++;
	}
	pointer--;
	return pointer;
}

char	*concat_and_clean(char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	free(s1);
	return (str);
}


char *prompt_concat(t_prompt *prompt)
{
	char 	*right_path;
	char	*result;

	right_path = find_path(prompt->path);

	result = ft_strdup(prompt->user);
	result = concat_and_clean(result, "@");
	result = concat_and_clean(result, prompt->hostname);
	result = concat_and_clean(result, ":~");
	result = concat_and_clean(result, right_path);
	result = concat_and_clean(result, "$ ");
	return (result);
}


int	main(int argc, char *argv[], char *envp[])
{
	char	**input;	
	t_prompt prompt;
	char *test;

	fill_prompt(&prompt);

	test = prompt_concat(&prompt);
	
	printf("%s\n", test);
	printf("%s\n", prompt.user);
	printf("%s\n", prompt.hostname);
	printf("%s\n", prompt.path);

	free(test);
	return (0);
}
