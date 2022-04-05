/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:56:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/05 10:35:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

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

	fd_aux = STDIN_FILENO;
	tmp = g_data.cmd_table->begin;
	while(tmp)
	{
		ft_exec_sys(tmp, &fd_aux);
		g_data.pipe_count--;
		tmp = tmp->next;
	}
	ft_close_fds(&fd_aux);
	// waitpid(pid, NULL, 0);
}
