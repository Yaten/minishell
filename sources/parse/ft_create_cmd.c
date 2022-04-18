/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/18 17:25:43 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_symbol(char *aux, char *line)
{
	if (!ft_strncmp(aux, "REDIR_OUTPUT", 12))
		return (ft_create_redir_output(line));
	else if (!ft_strncmp(aux, "APPEND_OUTPUT", 13))
		ft_create_append(line);
	else if (!ft_strncmp(aux, "REDIR_INPUT", 11))
		ft_create_redir_input(line);
	else if (!ft_strncmp(aux, "HERE_DOC", 8))
		ft_create_heredoc(line);
	else
	{
		ft_list_add_last(g_data.cmd_table, line);
		g_data.cmd_table->end->fd_in = dup(STDIN_FILENO);
		g_data.cmd_table->end->fd_out = dup(STDOUT_FILENO);
	}
	return (1);
}

int	ft_check_operators(char *line)
{
	char	*tmp;
	char	*aux;

	tmp = line;
	while (*tmp != '\0')
	{
		if (*tmp == '>')
		{
			aux = ft_strdup("REDIR_OUTPUT");
			if (*++tmp == '>')
				aux = ft_strdup("APPEND_OUTPUT");
		}
		if (*tmp == '<')
		{
			aux = ft_strdup("REDIR_INPUT");
			if (*++tmp == '<')
				aux = ft_strdup("HERE_DOC");
		}
		if (*tmp != '\0')
			++tmp;
	}
	return (ft_symbol(aux, line));
}

int	ft_create_cmd(char *line) // echo oi
{
	char	*aux;
	char	*tmp;

	if (!ft_check_operators(line))
		return (0);
	aux = ft_strdup(g_data.cmd_table->end->val[0]);
	tmp = ft_strdup(g_data.cmd_table->end->val[0]);
	if (ft_find_path(aux))
	{
		ft_builtin_path(g_data.cmd_table->end->path);
		// if (ft_builtin_path(g_data.cmd_table->end->path))
		// 	return (1);
		// 	// g_data.cmd_table->end->is_builtin = 1;
		// else
		// 	return (1);
		// 	// g_data.cmd_table->end->is_builtin = 0;
		return (1);
	}
	else if (ft_builtin_check(tmp))
	{
		// g_data.cmd_table->end->is_builtin = 1;
		return (1);
	}
	// else
	// 	ft_putstr_fd("Command not found fella, you r wrong >(\n", 2);
	return (1);
}
