/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:49:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/24 18:20:30 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_echo()
{
	int		i;
	int		boll_n;
	char	**tmp;

	i = 1;
	boll_n = 0;
	tmp = g_data.node->args;
	if (!ft_strncmp(tmp[i], "-n", 2))
	{
		boll_n = 1;
		++i;
	}
	while (tmp[i])
	{
		ft_putstr_fd(tmp[i], 1);
		if (tmp[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (!boll_n)
		ft_putstr_fd("\n", 1);
}
