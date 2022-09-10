/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:51:14 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/17 13:25:36 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	clean_exit(t_node *tmp)
{
	ft_putstr_fd("env: ‘", STDERR_FILENO);
	ft_putstr_fd(tmp->val[1], STDERR_FILENO);
	ft_putstr_fd("’: No such file or directory\n", STDERR_FILENO);
	ft_insert(g_data.array, "?", "127");
	return ;
}

int	ft_env(t_node *tmp)
{
	int		i;
	t_hnode	*temp;

	i = -1;
	if (tmp->val[1] != NULL)
	{
		clean_exit(tmp);
		return (1);
	}
	while (++i < TABLE_SIZE)
	{
		temp = g_data.array[i].head;
		while (temp)
		{
			ft_putstr_fd(temp->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putstr_fd(temp->value, STDOUT_FILENO);
			ft_putstr_fd("\n", STDOUT_FILENO);
			temp = temp->next;
		}
	}
	return (0);
}
