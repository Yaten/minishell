/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:21:56 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/17 14:49:31 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_parse.h"

t_circular	*ft_list_create()
{
	t_circular	*l;

	l = (t_circular *)ft_calloc(1, sizeof(t_circular));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return (l);
}
