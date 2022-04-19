/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:12:41 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/19 17:15:23 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void color_string(t_prompt *prompt)
{
	char	**strings;
	char	*test;

	strings = ft_split(prompt->result, ':');
	test = ft_sprintf("\e[31;1m%s\e[34;1m:\e[36;1m%s\e[0m$ ", \
	strings[0], strings[1]);
	free(prompt->result);
	free(strings[0]);
	free(strings[1]);
	free(strings);
	prompt->result = test;
}

int	concat_and_clean(t_prompt *prompt)
{
	char *pointer;

	pointer = ft_sprintf("%s@%s:%s", prompt->user, \
	prompt->hostname, prompt->path);
	if (!(pointer))
		exit(1);
	prompt->result = pointer;
	return (0);
}

void	ft_fill_prompt(t_prompt *prompt)
{
	prompt->user = getenv("USER");
	prompt->hostname = getenv("NAME");
	prompt->path = getenv("PWD");
}

void	ft_prompt_concat(t_prompt *prompt)
{
	ft_fill_prompt(prompt);
	concat_and_clean(prompt);
	color_string(prompt);
}
