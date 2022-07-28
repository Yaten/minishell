/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:51:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/07/25 17:32:09 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_create_heredoc(t_node **tmp)
{
	char	*s;
	char	*aux;

	unlink("here_doc.txt");
	(*tmp)->fd_in = open("here_doc.txt", O_WRONLY | \
	O_CREAT , 0777);
	g_data.signal_heredoc = 1;
	while (g_data.signal_heredoc)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		s = get_next_line(g_data.fd_heredoc);
		if (g_data.signal_heredoc)
		{
			if (!s)
			{
				close((*tmp)->fd_in);
				(*tmp)->fd_in = open("here_doc.txt", O_RDONLY | \
				O_CREAT, 0777);
				ft_putstr_fd("bash: warning: here-document ", STDOUT_FILENO);
				ft_putstr_fd("delimited by end-of-file (wanted `", STDOUT_FILENO);
				ft_putstr_fd(g_data.here_doc, STDOUT_FILENO);
				ft_putstr_fd("')", STDOUT_FILENO);
				ft_putstr_fd("\n", STDOUT_FILENO);
				free(s);
				break ;
			}
			aux = ft_strdup(s);
			aux[ft_strlen(aux) - 1] = '\0';
			if (!ft_strcmp(aux, g_data.here_doc))
			{
				free(s);
				free(aux);
				close((*tmp)->fd_in);
				(*tmp)->fd_in = open("here_doc.txt", O_RDONLY | \
				O_CREAT, 0777);
				break ;
			}
			ft_putstr_fd(s, (*tmp)->fd_in);
			free(s);
			free(aux);
		}
		else
		{
			(*tmp)->fd_in = 0;
			while (*tmp)
				*tmp = (*tmp)->next;
			break ;
		}
	}
}
