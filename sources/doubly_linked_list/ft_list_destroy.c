/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:26:39 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/17 14:52:34 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_parse.h"

void	ft_list_destroy(t_circular **l_ref)
{
	t_circular	*l;
	t_cmd		*p;
	t_cmd		*aux;

	l = *l_ref;
	p = l->head;
	while (p != NULL)
	{
		aux = p;
		p = p->next;
		free(aux);
	}
	free(l);
	*l_ref = NULL;
}
