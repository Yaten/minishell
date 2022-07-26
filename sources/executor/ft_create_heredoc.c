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

void	ft_create_heredoc(t_node *tmp)
{
	char	*s;

	unlink("here_doc.txt");
	tmp->fd_in = open("here_doc.txt", O_WRONLY | \
	O_CREAT , 0777);
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		s = get_next_line(0);
		if (!ft_strncmp(s, g_data.here_doc, ft_strlen(s) - 1))
		{
			free(s);
			close(tmp->fd_in);
			tmp->fd_in = open("here_doc.txt", O_RDONLY | \
			O_CREAT, 0777);
			break ;
		}
		ft_putstr_fd(s, tmp->fd_in);
		free(s);
	}
}
