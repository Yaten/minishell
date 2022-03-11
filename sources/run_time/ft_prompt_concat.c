/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_concat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 23:12:41 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/11 14:43:46 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"
# include "../../sprintf/include/ft_printf.h"

// não sei se realmente é necessario.
// lembram do caso root (sudo su)
/* Retorna o path retirando /home/nome_do_user */
char	*ft_find_path(char *abs_path)
{
	char *pointer;

	pointer = abs_path + 1;
	pointer = ft_strchr(pointer, '/');
	pointer++;
	pointer = ft_strchr(pointer, '/');
	return (pointer);
}

/* preenche a struct prompt com as variáveis de ambiente user, hostname e
path absoluto */
void	ft_fill_prompt(t_prompt *prompt)
{
	prompt->user = getenv("USER");
	prompt->hostname = getenv("NAME");
	prompt->path = getenv("PWD");
}

int	concat_and_clean(t_prompt *prompt)
{
	char *pointer;


	pointer = ft_printf("%s@%s:%s$ ", prompt->user, prompt->hostname, prompt->path);
	if (!(pointer))
		exit(1);
	prompt->result = pointer;
	return (0);
}

void color_string(t_prompt *prompt)
{
	char **strings;

	strings = ft_split(prompt->result, ':');
	char *teste = ft_printf("\e[32;1m%s\e[37;1m:\e[34;1m%s\e[0m$ ", strings[0], strings[1]);
	free(prompt->result);
	free(strings[0]);
	free(strings[1]);
	free(strings);
	prompt->result = teste;
}

/* Gera a linha do prompt de comando formatada */
void	ft_prompt_concat(t_prompt *prompt)
{
	ft_fill_prompt(prompt);
	concat_and_clean(prompt);
	color_string(prompt);
}
