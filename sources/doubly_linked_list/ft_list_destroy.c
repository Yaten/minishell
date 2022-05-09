/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:26:39 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/09 17:36:12 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_list_destroy(t_doubly **l_ref)
{
	t_doubly	*l;
	t_node		*p;
	t_node		*aux;
	int			i;

	l = *l_ref;
	p = l->begin;
	while (p != NULL)
	{
		aux = p;
		p = p->next;
		if (aux->list != NULL)
			ft_slist_destroy(&aux->list);
		i = 0;
		while (aux->val[i] != NULL)
			free(aux->val[i++]);
		free(aux->val);
		free(aux->path);
		// free (aux->operators);
		free (aux);

	}
	free(l);
	*l_ref = NULL;
}
