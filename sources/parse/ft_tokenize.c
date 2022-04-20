/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:11:53 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/20 16:16:04 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

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
	return (ft_syntax(token));
}

int	ft_is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || \
	c == '\v' || c == '\f');
}

static char	*ft_verify_token(char *end)
{
	while (!ft_strchr(" ><|", *end))
	{
		if (ft_strchr(" ><|", *end + 1))
			break ;
		end++;
	}
	return (end);
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
		end = ft_verify_token(end);
		if (ft_strchr("><|", *begin) && *begin)
		{
			if (*begin == *(begin + 1))
				end = end + 2;
			else
				end++;
		}
		ft_list_add_last(token, ft_substr(prompt->input_string, begin - prompt->input_string, end - begin));
		begin = end;
	}
	return (ft_define_token(token));
}
