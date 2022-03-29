/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:50:57 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/29 12:25:50 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_declare_x()
{
	int		i;
	t_hnode	*temp;

	i = -1;
	while (++i < TABLE_SIZE)
	{
		temp = g_data.array[i].head;
		while (temp)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(temp->key, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(temp->value, 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd("\n", 1);
			temp = temp->next;
		}
	}
}

void	ft_export()
{
	char	*tmp1;
	char	*before;
	char	*last;

	if (g_data.cmd_table->end->val[1] == NULL)
	{
		ft_declare_x();
		return ;
	}
	tmp1 = ft_strchr(g_data.cmd_table->end->val[1], '=');
	before = ft_substr(g_data.cmd_table->end->val[1], 0, tmp1 - g_data.cmd_table->end->val[1]);
	last = ft_substr(g_data.cmd_table->end->val[1], tmp1 + 1 - g_data.cmd_table->end->val[1], ft_strlen(g_data.cmd_table->end->val[1]));
	ft_insert(g_data.array, before, last);
	free (before);
	free (last);
}
