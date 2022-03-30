/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:16:20 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/30 14:17:55 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_create_pipe(char *line)
{
	char	*aux;
	char	*tmp;

	ft_list_add_last(g_data.cmd_table, line);
	aux = ft_strdup(g_data.cmd_table->end->val[0]);
	tmp = ft_strdup(g_data.cmd_table->end->val[0]);
	if (ft_find_path(aux))
	{
		if (ft_builtin_path(g_data.cmd_table->begin->path))
		{
			ft_builtin();
			return (0);
		}
		return (1);
	}
	else if (ft_builtin_check(tmp))
		ft_builtin();
	else
		ft_putstr_fd("Command not found fella, you r wrong >(\n", 2);
	return (0);
}