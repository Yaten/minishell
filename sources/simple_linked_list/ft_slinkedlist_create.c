/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slinkedlist_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:40:27 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/17 19:49:21 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

t_slist	*ft_slinkedlist_create()
{
	t_slist	*l;

	l = (t_slist *)calloc(1, sizeof(t_slist));
	l->begin = NULL;
	l->end = NULL;
	l->size = 0;
	return (l);
}
