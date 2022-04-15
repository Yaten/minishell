/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:31:48 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/14 21:19:39 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_dup_in(t_node *tmp, int *fd, int *fd_aux)
{
	if (!ft_strncmp(tmp->operators, "<<", 1))
		dup2(tmp->fd_in, STDIN_FILENO);
	else
		dup2(fd_aux[0], STDIN_FILENO);
	(void)fd;
	(void)tmp;
}
