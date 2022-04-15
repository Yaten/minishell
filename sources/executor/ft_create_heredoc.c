/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:51:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/14 21:19:39 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_create_heredoc(char *line)
{
	int		i;
	char	*s;
	char	**tmp;
	pid_t	pid;

	i = -1;
	unlink("here_doc.txt");
	tmp = ft_split(line, '<');
	while (tmp[++i])
		;
	ft_list_add_last(g_data.cmd_table, ft_strtrim(tmp[0], " "));
	g_data.cmd_table->end->fd_in = open("here_doc.txt", O_WRONLY | O_CREAT | O_TRUNC , 0777);
	// signal(SIGINT, here_doc_signal);
	g_data.here_bol = 1;
	pid = fork();
	if (pid == -1)
		perror("fork ");
	if (!pid)
	{
		signal(SIGINT, here_doc_signal);
		// signal(SIGINT, SIG_DFL);
		while (g_data.here_bol)
		{
			ft_putstr_fd("heredoc> ", 1);
			// s = readline("heredoc> ");
			s = get_next_line(0);
			if (!ft_strncmp(s, ft_strtrim(tmp[i - 1], " "), \
			ft_strlen(ft_strtrim(tmp[i - 1], " "))))
			{
				free(s);
				close(g_data.cmd_table->end->fd_in);
				exit(1);
			}
			ft_putendl_fd(s, g_data.cmd_table->end->fd_in);
			// ft_strlcat(aux, s, ft_strlen(aux) + ft_strlen(s) + 1);
			free(s);
		}
	}
	else
	{
		int	status;
		// int i;

		status = 0;
		wait(&status);
		// waitpid(pid, NULL, 0);
		// printf("status: %d\n", status);
		// return ;
		// i = WEXITSTATUS(status);
		// printf("retorno %d\n", i);
		if (WEXITSTATUS(status) == 1)
		{
			close(g_data.cmd_table->end->fd_in);
			g_data.cmd_table->end->fd_in = open("here_doc.txt", O_RDONLY | O_CREAT, 0777);
			g_data.cmd_table->end->operators = ft_strdup("<<");
		}
		// close(close(g_data.cmd_table->end->fd_in);
		// g_data.cmd_table->end->fd_in = open("here_doc.txt", O_RDONLY | O_CREAT, 0777);
		// g_data.cmd_table->end->operators = ft_strdup("<<");
	}
}
