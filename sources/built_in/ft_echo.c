/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:49:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/08 10:34:14 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_echo(t_node *tmp)
{
	int	i;
	int	boll_n;

	i = 1;
	boll_n = FALSE;
	if (tmp->val[1] == NULL)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return ;
	}
	if (!ft_strcmp(tmp->val[i], "-n"))
	{
		++i;
		boll_n = TRUE;
	}
	while (tmp->val[i])
	{
		ft_putstr_fd(tmp->val[i], STDOUT_FILENO);
		if (tmp->val[i + 1] != NULL)
			ft_putstr_fd(" ", STDOUT_FILENO);
		++i;
	}
	if (!boll_n)
		ft_putstr_fd("\n", STDOUT_FILENO);
}
