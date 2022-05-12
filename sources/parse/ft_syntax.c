/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:07:59 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/11 19:01:17 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_verify_pipe(t_node *tmp)
{
	if (tmp->prev == NULL || tmp->next == NULL || \
	tmp->next->operators == NULL)
	{
		ft_putendl_fd("Syntax error", 2);
		return (0);
	}
	return (1);
}

static int	ft_verify_operator(t_node *tmp)
{
	if (tmp->next == NULL || ft_strcmp(tmp->next->operators, "word"))
	{
		ft_putendl_fd("Syntax error", 2);
		return (0);
	}
	return (1);
}

int	ft_syntax()
{
	t_node	*tmp;

	tmp = g_data.token->begin;
	while (tmp)
	{
		if (!ft_strcmp(tmp->operators, "pipe"))
		{
			if (!ft_verify_pipe(tmp))
				return (0);
		}
		else if (!ft_strcmp(tmp->operators, "redir_output") || !ft_strcmp \
		(tmp->operators, "redir_append") || !ft_strcmp(tmp->operators, \
		"redir_input"))
		{
			if (!ft_verify_operator(tmp))
				return (0);
		}
		else if (tmp->operators == NULL)
		{
			if (tmp->next == NULL || tmp->prev == NULL)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}
