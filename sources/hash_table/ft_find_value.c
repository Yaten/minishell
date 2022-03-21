/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:48:10 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/21 11:23:07 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_find_value(t_hash *array, char *key)
{
	t_hash	*temp;
	int		i;

	i = -1;
	temp = array;
	while (++i < TABLE_SIZE)
	{
		while (temp[i].head)
		{
			if (!strcmp(temp[i].head->key, key))
				return (temp[i].head->value);
			temp[i].head = temp[i].head->next;
		}
	}
	return (NULL);
}
