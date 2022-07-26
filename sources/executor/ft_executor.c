/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:56:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/12 21:40:59 by wrosendo         ###   ########.fr       */
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
		close(fd--);
	close(fd_aux[0]);
	unlink("fd_tmp.txt");
}

static t_node	*ft_verify_heredoc()
{
	t_node	*tmp;

	tmp = g_data.cmd_table->begin;
	while (tmp)
	{
		if (tmp->heredoc_bool)
			return (tmp);
		tmp = tmp->next;
	}
	return (g_data.cmd_table->begin);
}

void	ft_exececutor(void)
{
	t_node	*tmp;
	int		fd_aux;

	fd_aux = dup(STDIN_FILENO);
	tmp = ft_verify_heredoc();
	if (tmp->heredoc_bool)
		ft_create_heredoc(tmp);
	ft_insert(g_data.array, "?", ft_strdup("0"));
	while (tmp)
	{
		if (tmp->is_builtin)
			ft_exec_builtin(tmp, &fd_aux);
		else
			ft_exec_sys(tmp, &fd_aux);
		tmp = tmp->next;
		g_data.pipe_count--;
	}
	ft_close_fds(&fd_aux);
	// waitpid(pid, NULL, 0);
	ft_list_destroy(&g_data.token);
	ft_list_destroy(&g_data.cmd_table);
}
