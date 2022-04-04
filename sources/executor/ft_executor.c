/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:56:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/03 09:55:45 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_exececutor()
{
	t_node	*tmp;
	int		fd_aux;
	int		fd;

	fd_aux = STDIN_FILENO;
	tmp = g_data.cmd_table->begin;
	while(tmp)
	{
		ft_exec_sys(tmp, &fd_aux);
		g_data.pipe_count--;
		// if (pipe(fd) == -1)
		// 	ft_putstr_fd("Error: Pipe gonna mad!!!\n", 2);
		// pid = fork();
		// if (pid == -1)
		// 	perror("");
		// if(!pid)
		// {
		// 	dup2(fd_in, STDIN_FILENO);
		// 	close(fd_in);
		// 	dup2(fd[1], STDOUT_FILENO);
		// 	// if (!ft_strncmp(tmp->relation, ">", 1))
		// 	// {
		// 	// 	dup2(tmp->fd_out, STDOUT_FILENO);
		// 	// 	g_data.pipe_count--;
		// 	// }
		// 	// else if (g_data.pipe_count)
		// 	// 	dup2(fd[1], STDOUT_FILENO);
		// 	// else if (!ft_strncmp(tmp->relation, "<", 1))
		// 	// {
		// 	// 	dup2(tmp->fd_in, STDIN_FILENO);
		// 	// 	g_data.pipe_count--;
		// 	// }
		// 	// else
		// 	// {
		// 	// 	dup2(fd_in, STDIN_FILENO);
		// 	// 	close(fd_in);
		// 	// }
		// 	// if (g_data.pipe_count)
		// 	// 	dup2(fd[1], STDOUT_FILENO);
		// 	if (execve(tmp->path, tmp->val, g_data.envp) == -1)
		// 	{
		// 		ft_putstr_fd("deu ruim no execve\n", 2);
		// 		exit (666);
		// 	}
		// }
		// else
		// {
		// 	waitpid(pid, NULL, 0);
		// 	fd_in = dup(fd[0]);
		// 	close(fd[1]);
		// 	// if(g_data.pipe_count)
		// 	// {
		// 	// 	close(fd[1]);
		// 	// 	// pipe(fd);
		// 	// 	g_data.pipe_count--;
		// 	// }
		// 	tmp = tmp->next;
		// }
		tmp = tmp->next;
	}
	fd = open("fd_tmp.txt", O_CREAT);
	while (fd > 2)
	{
		close(fd);
		fd--;
	}
	close(fd_aux);
	// waitpid(pid, NULL, 0);
}
