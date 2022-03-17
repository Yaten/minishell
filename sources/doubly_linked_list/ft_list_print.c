/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 19:05:28 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/17 14:52:56 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_parse.h"

void	ft_list_print(const t_circular *l)
{
	t_cmd	*tmp;
	tmp = l->head;

	while(tmp != NULL)
	{
		printf("%s\n", tmp->args);
		tmp = tmp->next;
	}
}
