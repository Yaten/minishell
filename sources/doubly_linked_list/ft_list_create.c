/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:21:56 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/16 19:00:11 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

t_doubly	*ft_list_create()
{
	t_doubly	*l;

	l = (t_doubly *)ft_calloc(1, sizeof(t_doubly));
	l->begin = NULL;
	l->end = NULL;
	l->size = 0;
	return (l);
}
