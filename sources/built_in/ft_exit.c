/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:51:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/15 10:34:42 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_exit(void)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = g_data.cmd_table->begin->val[1];
	if (g_data.cmd_table->begin->val[1] == NULL)
	{
		ft_clean_program();
		exit (EXIT_SUCCESS);
	}
	while (tmp[++i])
	{
		if (!ft_isdigit(tmp[i]))
		{
			printf("please dont use char my friend\n");
			exit (2);
		}
	}
	ft_clean_program();
	exit(ft_atoi(g_data.cmd_table->begin->val[1]));
}
