/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_last.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:00:46 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/16 19:25:38 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_list_add_last(t_doubly *l, int val)
{
	t_node	*new;

	new = ft_node_create(val);
	new->prev = l->end;
	if(ft_list_is_empty(l))
		l->begin = new;
	else
		l->end->next = new;
	l->end = new;
	l->size++;
}
