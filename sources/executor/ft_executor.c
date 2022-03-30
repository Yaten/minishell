/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:56:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/30 14:08:41 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

// void	ft_child_process(int *fd)
// {
// 	close(fd[0]);
// 	dup2(fd[1], STDOUT_FILENO);
// 	close(fd[1]);
// 	execve(g_data.node->args[0], g_data.node->args, g_data.envp);
// }
// void	ft_parent_process(int *fd, int pid)
// {
// 	close(fd[1]);
// 	dup2(fd[0], STDIN_FILENO);
// 	close(fd[0]);
// 	waitpid(pid, NULL, 0);
// }

void	ft_exec()
{
	int		fd[2];
	pid_t	pid;
	int		fd_in;
	t_node	*tmp;

	if (pipe(fd) == -1)
		ft_putstr_fd("Error: Pipe gonna mad!!!\n", 2);
	fd_in = 0;
	tmp = g_data.cmd_table->begin;
	while(tmp)
	{
		pid = fork();
		if(!pid)
		{
			dup2(fd_in, STDIN_FILENO);
			close(fd_in);
			if(g_data.pipe_count)
				dup2(fd[1], STDOUT_FILENO);
			if (execve(tmp->path, tmp->val, g_data.envp) == -1)
			{
				ft_putstr_fd("deu ruim no execve\n", 2);
				exit (666);
			}
		}
		else
		{
			waitpid(pid, NULL, 0);
			fd_in = dup(fd[0]);
			if(g_data.pipe_count)
			{
				close(fd[1]);
				pipe(fd);
				g_data.pipe_count--;
			}
			tmp = tmp->next;
		}
	}
	waitpid(pid, NULL, 0);
}

// void	ft_pipeline()
// {
// 	int		fd[2];
// 	pid_t	pid;
// 	if (pipe(fd) == -1)
// 		ft_putstr_fd("Error: Pipe gonna mad 2\n", 2);
// 	pid = fork();
// 	if (pid == -1)
// 		ft_putstr_fd("Error: Fork gonna mad\n", 2);
// 	if (!pid)
// 		ft_child_process(fd);
// 	else
// 		ft_parent_process(fd, pid);
// 	execve(g_data.node->args[0], g_data.node->args, g_data.envp);
// }
