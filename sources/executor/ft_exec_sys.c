/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:42:44 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/04 15:13:31 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

	// if (!ft_strncmp(tmp->relation, ">", 1))
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

void	ft_dup_out(t_node *tmp, int *fd)
{
	if (!ft_strncmp(tmp->relation, ">", 1))
		dup2(tmp->fd_out, STDOUT_FILENO);
	// if (!ft_strncmp(tmp->relation, ">>", 2))
	// 	dup2(tmp->fd_out, STDOUT_FILENO);
	else if (g_data.pipe_count)
		dup2(fd[1], STDOUT_FILENO);
	(void)fd;
	(void)tmp;
}

static void	ft_dup_in(t_node *tmp, int *fd, int *fd_aux)
{
	// if (!ft_strncmp(g_data.here_doc, "HERE_DOC", 8))

	if (!ft_strncmp(tmp->relation, "<", 1) || \
	!ft_strncmp(tmp->relation, "<<", 2))
		dup2(tmp->fd_in, STDIN_FILENO);
	else
		dup2(fd_aux[0], STDIN_FILENO);
	(void)fd;
	(void)tmp;
}

static void	ft_child_process(t_node *tmp, int *fd, int *fd_aux)
{
	ft_dup_in(tmp, fd, fd_aux);
	ft_dup_out(tmp, fd);
	close(fd[1]);
	close(fd[0]);
	// close(fd_aux[0]);
	if (execve(tmp->path, tmp->val, g_data.envp) == -1)
		perror("execve ");
}

static void	ft_parent_process(t_node *tmp, int *fd, pid_t pid, int *fd_aux)
{
	waitpid(pid, NULL, 0);
	*fd_aux = fd[0];
	close(fd[1]);
	(void)tmp;
	(void)pid;
	(void)fd_aux;
}

void	ft_exec_sys(t_node *tmp, int *fd_aux)
{
	int		fd[2];
	pid_t	pid;


	printf("fd do tmp->fd_in %d: ", tmp->fd_in);
	if (g_data.pipe_count > 0 && pipe(fd) == -1)
		perror("pipe ");
	pid = fork();
	if (pid == -1)
		perror("fork ");
	if(!pid)
	{
		ft_child_process(tmp, fd, fd_aux);
	}
	else
		ft_parent_process(tmp, fd, pid, fd_aux);
}
