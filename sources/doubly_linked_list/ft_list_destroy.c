/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:26:39 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/19 17:43:38 by prafael-         ###   ########.fr       */
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
		i = -1;
		while (aux->val[++i])
			free(aux->val[i]);
		free(aux->val);
		free (aux);
		free(aux->path);
	}
	free(l);
	*l_ref = NULL;
}
