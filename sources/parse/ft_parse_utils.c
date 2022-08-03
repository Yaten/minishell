/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/07/26 19:57:58 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_count_word(t_node *begin)
{
	t_node	*tmp;
	int		count_word;

	tmp = begin;
	count_word = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->operators, "word"))
			count_word++;
		tmp = tmp->next;
	}
	return (count_word);
}
