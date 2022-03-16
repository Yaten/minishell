/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:17:55 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/16 19:00:22 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

t_node	*ft_node_create(int	val)
{
	t_node	*node = (t_node *)ft_calloc(1, sizeof(t_node));
	node->prev = NULL;
	node->next = NULL;
	node->val = val;
	return (node);
}
