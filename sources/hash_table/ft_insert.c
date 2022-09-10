/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:48:52 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/16 21:58:37 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	ft_table_not_empty(t_hash *array, t_hnode *item, char *key)
{
	int		index;
	int		find_index;
	t_hnode	*list;

	index = ft_hashcode(key);
	list = (t_hnode *)array[index].head;
	find_index = ft_find_key(list, key);
	if (find_index == -1)
	{
		array[index].tail->next = item;
		array[index].tail = item;
		array[index].size++;
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = item;
		array[index].tail = item;
	}
}

static t_hnode	*ft_new_item(char *key, char *value)
{
	t_hnode	*new;

	new = (t_hnode *)malloc(sizeof(t_hnode));
	new->key = ft_strdup(key);
	if (!value)
		new->value = value;
	else
		new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

void	ft_insert(t_hash *array, char *key, char *value)
{
	t_insert_vars	vars;

	vars.index = ft_hashcode(key);
	vars.list = (t_hnode *)array[vars.index].head;
	if (ft_find_key(vars.list, key) != -1)
	{
		if (array[vars.index].head->value != NULL)
		{
			free (array[vars.index].head->value);
			array[vars.index].head->value = NULL;
		}
		if (value)
			array[vars.index].head->value = ft_strdup(value);
		return ;
	}
	vars.item = ft_new_item(key, value);
	if (array[vars.index].head == NULL)
	{
		array[vars.index].head = vars.item;
		array[vars.index].tail = vars.item;
		array[vars.index].size++;
	}
	else
		ft_table_not_empty(array, vars.item, key);
}
