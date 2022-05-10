/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snode_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:40:07 by wrosendo          #+#    #+#             */
/*   Updated: 2022/05/10 15:41:53 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

t_snode	*ft_snode_create(char *value)
{
	t_snode	*new;

	new = (t_snode *)calloc(1, sizeof(t_snode));
	new->next = NULL;
	new->val = value;
	return (new);
}
