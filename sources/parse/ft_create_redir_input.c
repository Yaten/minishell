/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_redir_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 09:02:01 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/04 08:15:50 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

// int		ft_isspace(char c)
// {
// 	return (c == ' ');
// }

// void	ft_create_redir_input(char *line)
// {
// 	int		index;
// 	char	*tmp;

// 	// 0123456789
// 	// < infile.txt grep willian
// 	while(line[index] != '\0')
// 	{
// 		if (line[index] == '<')
// 		{
// 			line[index] = '\0';
// 			// ft_create_cmd(line);
// 			// line += index + 1;
// 			// index = 0;
// 			// g_data.pipe_count++;
// 			index++;
// 		}
// 		if (!ft_isspace(line[index]))
// 		{
// 			tmp = ft_substr(line, index, line + index - ft_strchr(line + index, ' '));
// 		}
// 		index++;
// 	}
// }

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
	g_data.cmd_table->end->relation = ft_strdup("<");
}
