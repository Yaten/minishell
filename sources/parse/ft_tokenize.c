/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:11:53 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/11 19:01:39 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_define_token()
{
	t_node	*tmp;

	tmp = g_data.token->begin;
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
		else if (!ft_strcmp(tmp->val[0], ""))
			tmp->operators = NULL;
		else
			tmp->operators = "word";
		tmp = tmp->next;
	}
	return (ft_syntax());
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

int	ft_tokenize()
{
	char	*end;
	char	*tmp;
	char	*begin;
	int		amount_blanks;
	int		input_string_size;

	tmp = NULL;
	input_string_size = 0;
	begin = g_data.input_string;
	input_string_size = ft_strlen(g_data.input_string);
	while (*begin)
	{
		amount_blanks = 0;
		while (ft_is_space(*begin))
		{
			++amount_blanks;
			begin++;
		}
		end = begin;
		end = ft_verify_token(end);
		if (ft_strchr(" ><|", *begin) && *begin)
		{
			if (*begin == *(begin + 1))
				end = end + 2;
			else
				end++;
		}
		tmp = ft_substr(g_data.input_string, begin - g_data.input_string, \
		end - begin);
		if (input_string_size == amount_blanks)
			return (0);
		ft_list_add_last(g_data.token, tmp);
		if (!ft_strcmp(g_data.token->end->val[0], "\0"))
			g_data.token->end->val[0] = "space";
		free(tmp);
		begin = end;
		while (ft_is_space(*begin))
			begin++;
	}
	return (ft_define_token());
}
