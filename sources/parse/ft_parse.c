/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:53:01 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/11 21:04:24 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_parse()
{
	t_node	*end;
	t_node	*begin;

	end = g_data.token->begin;
	begin = g_data.token->begin;
	g_data.pipe_count = 0;
	while (end != NULL)
	{
		if (!ft_strcmp(end->val[0], "|"))
		{
			ft_create_cmd(begin, end);
			begin = end->next;
			g_data.pipe_count++;
		}
		end = end->next;
	}
	ft_create_cmd(begin, end);
	if (g_data.boll_paths)
		ft_exececutor();
	else
		ft_putstr_fd("command not found\n", STDERR_FILENO);
}
