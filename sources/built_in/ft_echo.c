/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:49:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/10 15:31:41 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_echo(t_node *tmp)
{
	int		i;
	int		boll_n;
	char	**aux;

	if (tmp->val[1] == NULL)
	{
		ft_putstr_fd("\n", 1);
		return ;
	}
	i = 1;
	boll_n = 0;
	aux = tmp->val;
	if (!ft_strncmp(aux[i], "-n", 2))
	{
		boll_n = 1;
		++i;
	}
	while (aux[i])
	{
		ft_putstr_fd(aux[i], 1);
		if (aux[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!boll_n)
		ft_putstr_fd("\n", 1);
}
