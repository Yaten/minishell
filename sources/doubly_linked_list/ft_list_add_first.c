/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:51:57 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/21 12:47:47 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_list_add_first(t_doubly *l, char *val)
{
	t_node	*new;

	new = ft_node_create(val);
	new->next = l->begin;
	if(ft_list_is_empty(l))
		l->end = new;
	else
		l->begin->prev = new;
	l->begin = new;
	l->size++;
}
