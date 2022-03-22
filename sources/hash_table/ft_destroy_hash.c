/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_hash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:38:55 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/21 09:58:12 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_destroy_hash(t_hash *array)
{
	t_hash	*temp;
	t_hash	*aux;
	int		i;

	i = -1;
	temp = array;
	while (++i < TABLE_SIZE)
	{
		while (temp[i].head)
		{
			free(temp[i].head->key);
			free(temp[i].head->value);
			aux = temp;
			temp[i].head = temp[i].head->next;
			free(aux[i].head);
			free(aux[i].tail);
		}
	}
	free(array);
}
