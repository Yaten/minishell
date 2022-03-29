/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snode_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:40:07 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/29 15:11:10 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

t_snode	*ft_snode_create(char *value)
{
	t_snode	*new;

	new = (t_snode *)calloc(1, sizeof(t_snode));
	new->next = NULL;
	new->val = value;
	return (new);
}
