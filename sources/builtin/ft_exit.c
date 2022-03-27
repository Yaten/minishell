/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:51:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 20:51:35 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_exit()
{
	int		i;
	char	*tmp;

	if (g_data.cmd_table->begin->val[1] == NULL)
		exit (0);
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