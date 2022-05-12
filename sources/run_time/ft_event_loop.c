/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/11 20:49:01 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_clean_program()
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_destroy_hash(g_data.array);
	// (void)prompt;
	exit(0);
}

int	ft_print_dir()
{
	char	*buf;

	buf = readline("MINISHELL> ");
	// free(prompt->result);
	if (!buf)
		ft_clean_program();
	if (*buf)
	{
		add_history(buf);
		ft_strlcpy(g_data.input_string, buf, MAXINPUT);
		free(buf);
		buf = NULL;
		return (0);
	}
	else
	{
		free(buf);
		return (1);
	}
}

void	ft_event_loop()
{
	// t_doubly	*token;

	while (TRUE)
	{
		// ft_prompt_concat(prompt);
		if (ft_print_dir() || ft_set_new_line())
			continue ;
		g_data.aux = g_data.input_string;
		ft_expand(g_data.aux, 0);
		ft_quoting(0);
		g_data.token = ft_list_create();
		if (!ft_tokenize())
			continue ;
		g_data.cmd_table = ft_list_create();
		ft_parse();
		// ft_list_destroy(&token);
		// ft_list_destroy(&g_data.cmd_table);
	}
}
