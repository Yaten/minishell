/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:51:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/05 09:29:17 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_create_heredoc(char *line)
{
	char	*s;
	char	**tmp;

	unlink("here_doc.txt");
	tmp = ft_split(line, '<');
	ft_list_add_last(g_data.cmd_table, ft_strtrim(tmp[0], " "));
	g_data.cmd_table->end->fd_in = open("here_doc.txt", O_WRONLY | O_CREAT , 0777);
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		s = get_next_line(0);
		if (!ft_strncmp(s, ft_strtrim(tmp[1], " "), \
		ft_strlen(ft_strtrim(tmp[1], " "))))
		{
			free(s);
			close(g_data.cmd_table->end->fd_in);
			break ;
		}
		ft_putstr_fd(s, g_data.cmd_table->end->fd_in);
		// ft_strlcat(aux, s, ft_strlen(aux) + ft_strlen(s) + 1);
		free(s);
	}
	g_data.cmd_table->end->fd_in = open("here_doc.txt", O_RDONLY | O_CREAT, 0777);
	g_data.cmd_table->end->relation = ft_strdup("<<");
}
