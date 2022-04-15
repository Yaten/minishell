/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_redir_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:02:01 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/14 21:19:39 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_create_redir_input(char *line)
{
	int		i;
	char	**split;

	split = ft_split(line, '<');
	ft_list_add_last(g_data.cmd_table, split[0]);
	g_data.cmd_table->end->list = ft_slinkedlist_create();
	i = 0;
	while (split[++i])
		ft_slist_add_last(g_data.cmd_table->end->list, ft_strtrim(split[i], " "));
	t_snode *aux;
	aux = g_data.cmd_table->end->list->begin;
	while (aux)
	{
		if (aux->next == NULL)
			g_data.cmd_table->end->fd_in = open(aux->val, O_RDONLY, 0777);
		else
			open(aux->val, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		aux = aux->next;
	}
	g_data.cmd_table->end->operators = ft_strdup("<");
}
