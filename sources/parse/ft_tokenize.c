/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:11:53 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/02 19:38:28 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_define_token(void)
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

static char	*ft_add_token_list(char *end, char *begin, char *tmp)
{
	if (*tmp == '\"' || *tmp == '\'')
	{
		tmp[ft_strlen(tmp) - 1] = '\0';
		ft_list_add_last(g_data.token, tmp + 1);
	}
	else
		ft_list_add_last(g_data.token, tmp);
	if (!ft_strcmp(g_data.token->end->val[0], "\0"))
		g_data.token->end->val[0] = "space";
	free(tmp);
	begin = end;
	while (ft_is_space(*begin))
		++begin;
	return (begin);
}

int	ft_tokenize(void)
{
	char	*end;
	char	*tmp;
	char	*begin;
	int		amount_blanks;
	int		input_string_size;

	begin = g_data.aux;
	g_data.token = ft_list_create();
	input_string_size = ft_strlen(g_data.aux);
	while (*begin)
	{
		amount_blanks = 0;
		while (ft_is_space(*begin))
		{
			++amount_blanks;
			++begin;
		}
		end = ft_verify_token(end, begin);
		tmp = ft_substr(g_data.aux, begin - g_data.aux, \
		end - begin);
		if (input_string_size == amount_blanks)
			return (FALSE);
		begin = ft_add_token_list(end, begin, tmp);
	}
	return (ft_define_token());
}
