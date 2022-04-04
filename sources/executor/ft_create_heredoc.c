/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:51:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/04 15:15:29 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_create_heredoc(char *line) // tr a y << eof
{
	//int		infile;
	// int		outfile;
	char	*s;
	char	**tmp;

	// ft_message(chest);
	unlink("here_doc.txt");
	// outfile = open(chest->argv[chest->argc - 1],
	// O_WRONLY | O_CREAT | O_TRUNC, 0777);
	tmp = ft_split(line, '<');
	ft_list_add_last(g_data.cmd_table, ft_strtrim(tmp[0], " "));
	g_data.cmd_table->end->fd_in = open("here_doc.txt", O_WRONLY | O_RDONLY | O_CREAT, 0777);
	if (g_data.cmd_table->end->fd_in == -1)
	{
		printf("deu caca no fd irmao\n");
		exit(42);
	}
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		s = get_next_line(0);
		if (!ft_strncmp(s, ft_strtrim(tmp[1], " "), \
		ft_strlen(ft_strtrim(tmp[1], " "))))
		{
			free(s);
			// close(infile);
			break ;
		}
		ft_putstr_fd(s, g_data.cmd_table->end->fd_in);
		free(s);
	}
	// infile = open("here_doc.txt", O_RDONLY | O_CREAT, 0777);
	// dup2(infile, STDIN_FILENO);
	// dup2(outfile, STDOUT_FILENO);
	g_data.cmd_table->end->relation = ft_strdup("<<");
}
