/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:50:11 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/25 14:32:25 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_cd()
{
	int	i;

	i = -1;
	while (g_data.node->args[++i])
		;
	if (i <= 2)
	{
		if (i == 1)
		{
			if (chdir("/home") == -1)
				perror("");
		}
		else if (i == 2)
		{
			if (chdir(g_data.node->args[1]) == -1)
				perror("");
		}
	}
	else
		ft_putstr_fd("too many arguments\n", STDOUT_FILENO);
}
