/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:56:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/06 11:41:59 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_exec_builtin(t_node *tmp, int *fd_aux)
{
	int		fd[2];
	int		backup[2];

	backup[0] = dup(STDIN_FILENO);
	backup[1] = dup(STDOUT_FILENO);
	dup2(backup[0], STDIN_FILENO);
	dup2(backup[1], STDOUT_FILENO);
	pipe(fd);
	ft_dup_out(tmp, fd);
	ft_builtin(tmp);
	close(fd[1]);
	fd_aux[0] = fd[0];
	dup2(backup[0], STDIN_FILENO);
	dup2(backup[1], STDOUT_FILENO);
}

static void	ft_close_fds(int *fd_aux)
{
	int	fd;

	fd = open("fd_tmp.txt", O_CREAT);
	while (fd > 2)
	{
		close(fd);
		fd--;
	}
	close(fd_aux[0]);
}

void	ft_exececutor()
{
	int		fd_aux;
	t_node	*tmp;
	// int		fd[2];
	// int		backup[2];

	// backup[0] = dup(STDIN_FILENO);
	// backup[1] = dup(STDOUT_FILENO);
	fd_aux = dup(STDIN_FILENO);
	tmp = g_data.cmd_table->begin;
	while(tmp)
	{
		if (tmp->is_buildin)
		{
			ft_exec_builtin(tmp, &fd_aux);
			// dup2(backup[0], STDIN_FILENO);
			// dup2(backup[1], STDOUT_FILENO);
			// pipe(fd);
			// ft_dup_out(tmp, fd);
			// ft_builtin(tmp);
			// close(fd[1]);
			// fd_aux = fd[0];
			// dup2(backup[0], STDIN_FILENO);
			// dup2(backup[1], STDOUT_FILENO);
		}
		else
			ft_exec_sys(tmp, &fd_aux);
		g_data.pipe_count--;
		tmp = tmp->next;
	}
	ft_close_fds(&fd_aux);
	// waitpid(pid, NULL, 0);
}
