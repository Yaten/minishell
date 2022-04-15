/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_sys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:42:44 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/14 21:19:39 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

// static void	ft_dup_out(t_node *tmp, int *fd)
// {
// 	if (!ft_strncmp(tmp->operators, ">>", 1))
// 		dup2(tmp->fd_out, STDOUT_FILENO);
// 	else if (g_data.pipe_count)
// 		dup2(fd[1], STDOUT_FILENO);
// 	(void)fd;
// 	(void)tmp;
// }

// static void	ft_dup_in(t_node *tmp, int *fd, int *fd_aux)
// {
// 	if (!ft_strncmp(tmp->operators, "<<", 1))
// 		dup2(tmp->fd_in, STDIN_FILENO);
// 	else
// 		dup2(fd_aux[0], STDIN_FILENO);
// 	(void)fd;
// 	(void)tmp;
// }

int	*ft_handler_error(t_node *tmp)
{
	perror(tmp->val[0]);
	exit(-1);
}

static void	ft_child_process(t_node *tmp, int *fd, int *fd_aux)
{
	int	result;

	ft_dup_in(tmp, fd, fd_aux);
	ft_dup_out(tmp, fd);
	close(fd[1]);
	close(fd[0]);
	// close(fd_aux[0]);
	result = execve(tmp->path, tmp->val, g_data.envp);
	if (result != 0)
	{
		if (!ft_find_path(tmp->val[0]))
		{
			ft_putstr_fd(tmp->val[0], 2);
			ft_putstr_fd(": command not found\n", 2);
			exit(127);
		}
		else
		{
			perror(tmp->val[0]);
			exit(result);
		}
	}
	// if (execve(tmp->path, tmp->val, g_data.envp) == -1)
	// {
	// 	// perror("execve ");
	// 	status = ft_handler_error(tmp);
	// 	// exit(-1);
	// }
}

static void	ft_parent_process(t_node *tmp, int *fd, pid_t pid, int *fd_aux)
{
	int	status;

	status = 0;
	wait(&status);
	ft_insert(g_data.array, "?", ft_itoa(WEXITSTATUS(status)));
	// waitpid(pid, status, WUNTRACED);
	// if (WIFEXITED(*status))
	// 	ft_insert(g_data.array, "?", ft_itoa(WEXITSTATUS(*status)));
	//  ft_itoa(WEXITSTATUS(status));
	// ft_insert(g_data.array, "?", ft_itoa(WEXITSTATUS(*status)));
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

	if (g_data.pipe_count > 0 && pipe(fd) == -1)
		perror("pipe ");
	pid = fork();
	if (pid == -1)
		perror("fork ");
	if(!pid)
		ft_child_process(tmp, fd, fd_aux);
	else
		ft_parent_process(tmp, fd, pid, fd_aux);
}
