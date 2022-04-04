/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:56:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/30 15:33:19 by wrosendo         ###   ########.fr       */
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

// static void	ft_child_process(t_node	*tmp)
// {

// }

// static void	ft_parent_process(int *fd, int pid)
// {

// }

void	ft_redir()
{
	pid_t	pid;
	t_node	*tmp;

	tmp = g_data.cmd_table->end;
	while(tmp)
	{
		pid = fork();
		if(!pid)
		{
			dup2(tmp->fd_out, STDOUT_FILENO); // ls > lkdjf > lsjf
			close(tmp->fd_out);
			if (execve("/usr/bin/ls", tmp->val, g_data.envp) == -1)
			{
				ft_putstr_fd("deu ruim no execve\n", 2);
				exit (666);
			}
		}
		else
			waitpid(pid, NULL, 0);
		tmp = tmp->next;
	}

	// while(tmp)
	// {
	// 	pid = fork();
	// 	if(!pid)
	// 	{
	// 		infile = open(tmp->list->begin->val, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	// 		dup2(fd_in, STDIN_FILENO);
	// 		close(fd_in);
	// 		dup2(infile, STDOUT_FILENO);
	// 		close(infile);
	// 		// if(g_data.pipe_count)
	// 		// 	dup2(fd[1], STDOUT_FILENO);
	// 		if (execve("/usr/bin/ls", tmp->val, g_data.envp) == -1)
	// 		{
	// 			ft_putstr_fd("deu ruim no execve\n", 2);
	// 			exit (666);
	// 		}
	// 	}
	// 	else
	// 	{
	// 		waitpid(pid, NULL, 0);
	// 		fd_in = dup(fd[0]);
	// 		if(g_data.pipe_count)
	// 		{
	// 			close(fd[1]);
	// 			pipe(fd);
	// 			g_data.pipe_count--;
	// 		}
	// 		tmp = tmp->next;
	// 	}
	// }
	//waitpid(pid, NULL, 0);
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
