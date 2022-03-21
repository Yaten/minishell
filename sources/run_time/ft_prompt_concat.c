/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:12:41 by prafael-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/21 10:07:22 by wrosendo         ###   ########.fr       */
=======
/*   Updated: 2022/03/18 01:40:01 by prafael-         ###   ########.fr       */
>>>>>>> 3c849b225c0ebc693d1d321599472c5df06d905c
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_fill_prompt(t_prompt *prompt)
{
	prompt->user = getenv("USER");
	prompt->hostname = getenv("NAME");
	prompt->path = getenv("PWD");
}

int	concat_and_clean(t_prompt *prompt)
{
	char *pointer;

<<<<<<< HEAD
	pointer = ft_sprintf("%s@%s:%s", prompt->user, \
	prompt->hostname, prompt->path);
=======

	pointer = ft_sprintf("ft_%s@%s:%s", prompt->user, prompt->hostname, prompt->path);
>>>>>>> 3c849b225c0ebc693d1d321599472c5df06d905c
	if (!(pointer))
		exit(1);
	prompt->result = pointer;
	return (0);
}

void color_string(t_prompt *prompt)
{
	char	**strings;
	char	*teste;

	strings = ft_split(prompt->result, ':');
<<<<<<< HEAD
	teste = ft_sprintf("\e[32;1m%s\e[37;1m:\e[34;1m%s\e[0m$ ", \
	strings[0], strings[1]);
=======
	char *teste = ft_sprintf("\e[35;1m%s\e[37;1m:\e[34;1m%s\e[0m$ ", strings[0], strings[1]);
>>>>>>> 3c849b225c0ebc693d1d321599472c5df06d905c
	free(prompt->result);
	free(strings[0]);
	free(strings[1]);
	free(strings);
	prompt->result = teste;
}

void	ft_prompt_concat(t_prompt *prompt)
{
	ft_fill_prompt(prompt);
	concat_and_clean(prompt);
	color_string(prompt);
}
