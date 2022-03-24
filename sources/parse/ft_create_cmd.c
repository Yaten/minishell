/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 21:52:26 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_create_cmd(char *line)
{
	t_node *node;
	t_node *last;

	last = g_data.node;
	node = (t_node *)malloc(sizeof(t_node));
	node->args = ft_split(line, ' ');
	node->relation = g_data.operators[0];
	node->next = NULL;
	node->fd_in = 0;
	node->fd_out = 0;
	if (!ft_find_path(node))
	{
		g_data.node = node;
		if (ft_builtin_check())
		{
			ft_builtin();
			return (0);
		}
		else
			ft_putstr_fd("Command not found fella, you r wrong >(\n", 2);
		return (0);
	}
	else if (!ft_strncmp(node->args[0], "pwd", 3))
	{
		ft_pwd();
		return (0);
	}
	if(last != NULL)
	{
		while(last->next)
			last = last->next;
		last->next = node;
	}
	else
		g_data.node = node;
	return (1);
}
