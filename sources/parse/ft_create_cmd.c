/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/04 14:34:16 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

// char	*ft_symbol(char *line)
// {
// 	char	*tmp;
// 	char	*aux;

// 	tmp = line;
// 	while (*tmp != '\0')
// 	{
// 		if (*tmp == '>')
// 		{
// 			aux = ft_strdup("REDIR_OUTPUT");
// 			tmp++;
// 			if (*tmp == '>')
// 				aux = ft_strdup("APPEND_OUTPUT");
// 		}
// 		if (*tmp == '<')
// 		{
// 			aux = ft_strdup("REDIR_INPUT");
// 			tmp++;
// 			if (*tmp == '<')
// 				aux = ft_strdup("HERE_DOC");
// 		}
// 		tmp++;
// 	}
// }

void	ft_check_operators(char *line)
{
	char	*tmp;
	char	*aux;

	// aux = ft_symbol(line);
	tmp = line;
	while (*tmp != '\0')
	{
		if (*tmp == '>')
		{
			aux = ft_strdup("REDIR_OUTPUT");
			tmp++;
			if (*tmp == '>')
				aux = ft_strdup("APPEND_OUTPUT");
		}
		if (*tmp == '<')
		{
			aux = ft_strdup("REDIR_INPUT");
			tmp++;
			if (*tmp == '<')
				aux = ft_strdup("HERE_DOC");
		}
		tmp++;
	}
	g_data.here_doc = ft_strdup(aux);
	if (!ft_strncmp(aux, "REDIR_OUTPUT", 12))
		ft_create_redir_output(line);
	else if (!ft_strncmp(aux, "APPEND_OUTPUT", 13))
		ft_create_append(line);
	else if (!ft_strncmp(aux, "REDIR_INPUT", 11))
		ft_create_redir_input(line);
	else if (!ft_strncmp(g_data.here_doc, "HERE_DOC", 8))
		ft_create_heredoc(line);
	else
	{
		ft_list_add_last(g_data.cmd_table, line);
		g_data.cmd_table->end->fd_in = STDIN_FILENO;
		g_data.cmd_table->end->fd_out = STDOUT_FILENO;
	}
	// free(aux);
}

int	ft_create_cmd(char *line)
{
	char	*aux;
	char	*tmp;

	ft_check_operators(line);
	// ft_list_add_last(g_data.cmd_table, line);

	// g_data.cmd_table->end->fd_in = STDIN_FILENO;
	// g_data.cmd_table->end->fd_out = STDOUT_FILENO;
	aux = ft_strdup(g_data.cmd_table->end->val[0]);
	tmp = ft_strdup(g_data.cmd_table->end->val[0]);
	if (ft_find_path(aux))
	{
		if (ft_builtin_path(g_data.cmd_table->begin->path))
		{
			ft_builtin();
			return (0);
		}
		return (1);
	}
	else if (ft_builtin_check(tmp))
		ft_builtin();
	else
		ft_putstr_fd("Command not found fella, you r wrong >(\n", 2);
	return (0);
}
