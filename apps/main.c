/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/09 15:59:46 by rsiqueir         ###   ########.fr       */
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

char *prompt_concat(t_prompt *prompt)
{
	char *right_path;

	right_path = find_path(prompt->path);
	printf("%s@%s:~%s$ ", prompt->user, prompt->hostname, right_path);
}


int	main(int argc, char *argv[], char *envp[])
{
	char	**input;	
	t_prompt prompt;

	fill_prompt(&prompt);

	prompt_concat(&prompt);

	
	printf("%s\n", prompt.user);
	printf("%s\n", prompt.hostname);
	printf("%s\n", prompt.path);

	// ft_event_loop(input);
	return (0);
}
