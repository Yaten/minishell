/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_hash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:38:55 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/23 13:02:37 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_destroy_hash(t_hash *array)
{
	t_hash	*temp;
	t_hnode	*aux;
	int		i;
    int     index;

	i = -1;
	temp = array;
	index = ft_hashcode("?");
	if (ft_find_key((t_hnode *)array[index].head, "?") != -1)
	{
        free (array[index].head->value);
    }
	while (++i < TABLE_SIZE)
	{
		while (temp[i].head)
		{
            if (temp[i].head->key != NULL)
            {
                if (ft_strcmp(temp[i].head->key, "?"))
        			free(temp[i].head->value);
	    		free(temp[i].head->key);
            }
			aux = temp[i].head;
			temp[i].head = temp[i].head->next;
			free(aux);
		}
	}
	free(array);
}
