/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_add_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:39:39 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/17 19:49:26 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_slist_add_last(t_slist *l, int val)
{
	t_snode	*new;

	new = ft_snode_create(val);
	if (ft_slist_is_empty(l))
		l->begin = new;
	else
		l->end->next = new;
	l->end = new;
	l->size++;
}
