/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:51:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/02 15:54:45 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_exit()
{
	int		i;
	char	*tmp;

	if (g_data.cmd_table->begin->val[1] == NULL)
		exit (EXIT_SUCCESS);
	i = -1;
	tmp = g_data.cmd_table->begin->val[1];
	while (tmp[++i])
	{
		if (!ft_isdigit(tmp[i]))
		{
			printf("please dont use char my friend\n");
			exit (2);
		}
	}
	exit(ft_atoi(g_data.cmd_table->begin->val[1]));
}
