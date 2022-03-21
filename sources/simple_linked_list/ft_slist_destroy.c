/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:32:50 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/17 19:50:29 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_slist_destroy(t_slist **l_ref)
{
	t_slist	*l;
	t_snode	*p;
	t_snode	*aux;

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
