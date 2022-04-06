/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:32:15 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/06 11:34:29 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_dup_out(t_node *tmp, int *fd)
{
	if (!ft_strncmp(tmp->relation, ">>", 1))
		dup2(tmp->fd_out, STDOUT_FILENO);
	else if (g_data.pipe_count)
		dup2(fd[1], STDOUT_FILENO);
	(void)fd;
	(void)tmp;
}
