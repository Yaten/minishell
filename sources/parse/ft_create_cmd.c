/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/09 16:42:20 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_open_files(t_node *begin, t_node *node)
{
	
}

t_node	*ft_add_command(t_node *begin, t_node *node)
{
	int	i;

	i = 0;
	while (begin)
	{
		if (!ft_strcmp(begin->operators, "word"))
		{
			node->operators = "|";
			node->val[i++] = ft_strdup(begin->val[0]);
		}
		else if (!ft_strcmp(begin->operators, "redir_input"))
		{
			close (node->fd_in);
			node->fd_in = open(begin->next->val[0], O_RDONLY , 0777);
			node->operators = "redir_input";
			node->operator_input = 1;
			begin = begin->next;
		}
		else if (!ft_strcmp(begin->operators, "redir_output"))
		{
			close (node->fd_out);
			node->fd_out = open(begin->next->val[0], O_WRONLY | O_CREAT | O_TRUNC, 0777);
			node->operators = "redir_output";
			node->operator_output = 1;
			begin = begin->next;
		}
		else if (!ft_strcmp(begin->operators, "redir_append"))
		{
			close (node->fd_out);
			node->fd_out = open(begin->next->val[0], O_WRONLY | O_CREAT | O_APPEND, 0777);
			node->operators = "redir_append";
			node->operator_output = 1;
			begin = begin->next;
		}
		else
			break ;
		begin = begin->next;
	}
	node->val[i] = NULL;
	node->prev = g_data.cmd_table->end;
	if(ft_list_is_empty(g_data.cmd_table))
		g_data.cmd_table->begin = node;
	else
		g_data.cmd_table->end->next = node;
	g_data.cmd_table->end = node;
	g_data.cmd_table->size++;
	return (begin);
}

int	ft_count_word(t_node *begin)
{
	int		count_word;
	t_node	*tmp;

	tmp = begin;
	count_word = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->operators, "word"))
		{
			tmp = tmp->next;
			count_word++;
		}
		else
			break ;
	}
	return (count_word);
}

t_node	*ft_new_node_table(t_node *begin)
{
	t_node	*node;
	int		count_word;

	count_word = ft_count_word(begin);
	node = (t_node *)ft_calloc(1, sizeof(t_node));
	node->prev = NULL;
	node->next = NULL;
	node->path = NULL;
	node->operator_input = 0;
	node->operator_output = 0;
	node->fd_in = dup(STDIN_FILENO);
	node->fd_out = dup(STDOUT_FILENO);
	node->val = (char **)malloc(sizeof(char) * count_word);
	return (ft_add_command(begin, node));
}

void	ft_fill_table(t_node *begin, t_node *end)
{
	while (begin != end)
	{
		if (!ft_strcmp(begin->operators, "word") && \
		(begin->prev == NULL || !ft_strcmp(begin->prev->operators, "pipe")))
			begin = ft_new_node_table(begin);
		else
			begin = ft_new_node_table(begin);
	}
}

void	ft_create_cmd(t_node *begin, t_node *end)
{
	ft_fill_table(begin, end);
	ft_find_path(g_data.cmd_table->end->val[0]);
	ft_builtin_path(g_data.cmd_table->end->path);
	ft_builtin_check(g_data.cmd_table->end->path);
}
