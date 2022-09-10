/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:50:57 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/16 20:45:01 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_declare_x(void)
{
	int		i;
	t_hnode	*temp;

	i = -1;
	while (++i < TABLE_SIZE)
	{
		temp = g_data.array[i].head;
		while (temp)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(temp->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
			ft_putstr_fd(temp->value, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
			temp = temp->next;
		}
	}
}

void	ft_export(t_node *tmp)
{
	char	*last;
	char	*before;

	last = NULL;
	if (tmp->val[1] == NULL)
	{
		ft_declare_x();
		return ;
	}
	before = tmp->val[1];
	if (tmp->val[2] && *tmp->val[2] == '=')
	{
		if (!tmp->val[3])
			ft_insert(g_data.array, before, last);
		else
		{
			last = ft_strdup(tmp->val[3]);
			if (!ft_strcmp(tmp->val[3], "no"))
				ft_insert(g_data.array, before, last);
			else
				ft_insert(g_data.array, before, last);
			free(last);
		}
	}
}
