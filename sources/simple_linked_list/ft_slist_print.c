/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slist_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:39:19 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/17 19:49:39 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_slist_print(const t_slist *l)
{
	t_snode	*tmp;

	tmp = l->begin;
	printf("Size: %d ", l->size);
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->val);
		tmp = tmp->next;
	}
	puts("");
}
