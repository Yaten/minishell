/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:51:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/02 17:16:26 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_read_here(t_node **tmp, char *s)
{
	char	*aux;

	aux = ft_strdup(s);
	aux[ft_strlen(aux) - 1] = '\0';
	if (!ft_strcmp(aux, g_data.here_doc))
	{
		free(s);
		free(aux);
		close((*tmp)->fd_in);
		(*tmp)->fd_in = open("here_doc.txt", O_RDONLY | \
		O_CREAT, 0777);
		return (TRUE);
	}
	ft_putstr_fd(s, (*tmp)->fd_in);
	free(s);
	free(aux);
	return (FALSE);
}

static int	ft_ctrl_d(t_node **tmp, char *s)
{
	if (!s)
	{
		close((*tmp)->fd_in);
		(*tmp)->fd_in = open("here_doc.txt", O_RDONLY | \
		O_CREAT, 0777);
		ft_putstr_fd(YELLOW"bash: warning: here-document ", \
			STDOUT_FILENO);
		ft_putstr_fd("delimited by ", STDOUT_FILENO);
		ft_putstr_fd("end-of-file (wanted `", STDOUT_FILENO);
		ft_putstr_fd(g_data.here_doc, STDOUT_FILENO);
		ft_putstr_fd("')", STDOUT_FILENO);
		ft_putstr_fd("\n"RESET, STDOUT_FILENO);
		free(s);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_create_heredoc(t_node **tmp)
{
	char	*s;

	unlink("here_doc.txt");
	(*tmp)->fd_in = open("here_doc.txt", O_WRONLY | \
	O_CREAT, 0777);
	g_data.signal_heredoc = 1;
	while (g_data.signal_heredoc)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		s = get_next_line(g_data.fd_heredoc);
		if (g_data.signal_heredoc)
		{
			if (ft_ctrl_d(tmp, s) || ft_read_here(tmp, s))
				break ;
		}
		else
		{
			(*tmp)->fd_in = STDIN_FILENO;
			while (*tmp)
				*tmp = (*tmp)->next;
			break ;
		}
	}
}
