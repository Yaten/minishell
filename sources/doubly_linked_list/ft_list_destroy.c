/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:26:39 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/21 12:14:54 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_list_destroy(t_doubly **l_ref)
{
	t_doubly	*l;
	t_node		*p;
	t_node		*aux;

	l = *l_ref;
	p = l->begin;
	while (p != NULL)
	{
		aux = p;
		p = p->next;
		free(aux);
	}
	free(l);
	*l_ref = NULL;
}
