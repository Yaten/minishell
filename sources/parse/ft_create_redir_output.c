/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_redir_output.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:20:36 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/18 17:29:55 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_create_redir_output(char *line)
{
	int		i;
	int		bool_j;
	char	**split;

	split = ft_split(line, '>');
	ft_list_add_last(g_data.cmd_table, split[0]);
	g_data.cmd_table->end->list = ft_slinkedlist_create();
	i = 0;
	if (split[1] == NULL)
		bool_j = 0;
	else
		bool_j = 1;
	while (split[++i])
		ft_slist_add_last(g_data.cmd_table->end->list, ft_strtrim(split[i], " "));
	while (split[i++] == NULL)
		ft_slist_add_last(g_data.cmd_table->end->list, ft_strtrim(split[0], " "));
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
	g_data.cmd_table->end->operators = ft_strdup(">");
	return (bool_j);
}
