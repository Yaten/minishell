/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:05:28 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/10 15:37:12 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_list_print(const t_doubly *l)
{
	t_node	*tmp;

	tmp = l->begin;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->val[0]);
		tmp = tmp->next;
	}
}

void	ft_list_print2(const t_doubly *l)
{
	t_node	*tmp;

	tmp = l->begin;
	while (tmp != NULL)
	{
		if (tmp->operators == NULL)
		{
			printf("operator NULL\n");
			break ;
		}
		printf("%s\n", tmp->operators);
		tmp = tmp->next;
	}
}
