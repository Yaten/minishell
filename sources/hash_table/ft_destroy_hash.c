/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_hash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:38:55 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/16 21:02:35 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_destroy_hash(t_hash *array)
{
	int		i;
	t_hnode	*aux;
	t_hash	*temp;

	i = -1;
	temp = array;
	while (++i < TABLE_SIZE)
	{
		while (temp[i].head)
		{
			if (temp[i].head->key != NULL)
			{
				if (temp[i].head->value != NULL)
				{
					free(temp[i].head->value);
					temp[i].head->value = NULL;
				}
				free(temp[i].head->key);
			}
			aux = temp[i].head;
			temp[i].head = temp[i].head->next;
			free(aux);
		}
	}
	free(array);
}
