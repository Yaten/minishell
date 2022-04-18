/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:11:53 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/18 17:00:31 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_syntax(t_doubly *token)
{
	t_node	*tmp;

	tmp = token->begin;
	while (tmp)
	{
		if (!ft_strcmp(tmp->operators, "pipe"))
		{
			if (tmp->prev == NULL || tmp->next == NULL || \
			tmp->next->operators == NULL)
			{
				ft_putendl_fd("Syntax error", 2);
				return (0);
			}
		}
		else if (!ft_strcmp(tmp->operators, "redir_output") || !ft_strcmp(tmp->operators, "redir_append") || !ft_strcmp(tmp->operators, "redir_input"))
		{
			if (tmp->next == NULL || ft_strcmp(tmp->next->operators, "word"))
			{
				ft_putendl_fd("Syntax error2", 2);
				return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_define_token(t_doubly *token)
{
	t_node	*tmp;

	tmp = token->begin;
	while (tmp)
	{
		if (!ft_strcmp(tmp->val[0], "|"))
			tmp->operators = "pipe";
		else if (!ft_strcmp(tmp->val[0], "<"))
			tmp->operators = "redir_input";
		else if (!ft_strcmp(tmp->val[0], "<<"))
			tmp->operators = "here_doc";
		else if (!ft_strcmp(tmp->val[0], ">"))
			tmp->operators = "redir_output";
		else if (!ft_strcmp(tmp->val[0], ">>"))
			tmp->operators = "redir_append";
		else if (tmp->val[0] == NULL)
			tmp->operators = NULL;
		else
			tmp->operators = "word";
		tmp = tmp->next;
	}
	// ft_list_print2(token);
	return (ft_syntax(token));
}

int	ft_is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || \
	c == '\v' || c == '\f');
}

int	ft_tokenize(t_prompt *prompt)
{
	char		*begin;
	char		*end;
	t_doubly	*token;

	token = ft_list_create();
	begin = prompt->input_string;
	while (*begin)
	{
		while (ft_is_space(*begin))
			begin++;
		end = begin;
		while (!ft_strchr(" ><|", *end))
		{
			if (ft_strchr(" ><|", *end + 1))
				break ;
			end++;
		}
		if (ft_strchr("><|", *begin) && *begin)
		{
			if (*begin == *(begin + 1))
				end = end + 2;
			else
				end++;
		}
		ft_list_add_last(token, ft_substr(prompt->input_string, \
		begin - prompt->input_string, end - begin + 1));
		begin = end;
	}
	return (ft_define_token(token));
	// ft_list_print(token);
}
