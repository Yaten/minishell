/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_redir_output.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:20:36 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/30 14:30:27 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_create_redir_output(char *line)
{
	int		i;
	char	**split;

	split = ft_split(line, '>');
	ft_list_add_last(g_data.cmd_table, split[0]);
	g_data.cmd_table->end->list = ft_slinkedlist_create();
	i = 0;
	while (split[++i])
		ft_slist_add_last(g_data.cmd_table->end->list, split[i]);
	t_snode *aux;
	aux = g_data.cmd_table->end->list->begin;
	while (aux)
	{
		if (aux->next == NULL)
			g_data.cmd_table->end->fd_out = open(aux->val, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		else
			open(aux->val, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		aux = aux->next;
	}
}
