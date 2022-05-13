/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/12 17:37:14 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_clean_program()
{
	ft_putstr_fd("\n", STDOUT_FILENO);
	ft_destroy_hash(g_data.array);
	exit(FALSE);
}

int	ft_print_dir()
{
	char	*buf;

	buf = readline(RED"MINISHELL> "RESET);
	if (!buf)
		ft_clean_program();
	if (*buf)
	{
		add_history(buf);
		ft_strlcpy(g_data.input_string, buf, MAXINPUT);
		free(buf);
		buf = NULL;
		return (FALSE);
	}
	else
	{
		free(buf);
		return (TRUE);
	}
}

void	ft_event_loop()
{
	while (TRUE)
	{
		if (ft_print_dir() || ft_set_new_line())
			continue ;
		g_data.aux = g_data.input_string;
		ft_expand(g_data.aux, FALSE);
		ft_quoting(FALSE);
		if (!ft_tokenize())
			continue ;
		ft_parse();
		ft_exececutor();
	}
}
