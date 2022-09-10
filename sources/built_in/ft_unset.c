/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:51:04 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/16 21:27:02 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_unset(void)
{
	int	i;

	i = 0;
	while (++i)
	{
		if (g_data.cmd_table->begin->val[i] != NULL)
			ft_remove_element(g_data.array, g_data.cmd_table->begin->val[i]);
		else
			break ;
	}
}
