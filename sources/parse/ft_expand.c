/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 07:25:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/10 15:25:34 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

char	*ft_expand_last(char *tmp)
{
	while (*tmp && !ft_strchr(SEPARATORS, *tmp))
		++tmp;
	return (tmp);
}

char	*ft_getvalue(char *value)
{
	char	*content;

	content = getenv((value));
	if (!content)
		return ("");
	return (content);
}

void	ft_chunk(char *input_string, char *tmp)
{
	char	*first;
	char	*last;
	char	*middle;
	char	*former;
	char	*aux;

	first = ft_substr(input_string, 0, tmp - input_string);
	last = ft_expand_last(tmp + 1);
	if (!ft_strncmp(last, "?", 1))
		middle = ft_find_value(last);
	else
	{
		middle = ft_substr(input_string, tmp + 1 - input_string, \
		last - tmp - 1);
		middle = ft_getvalue(middle);
	}
	last = ft_strdup(last);
	former = ft_strjoin(first, middle);
	if (!ft_strncmp(last, "?", 1))
		g_data.aux = ft_strdup(former);
	else
	{
		aux = ft_strjoin(former, last);
		g_data.aux = ft_strdup(aux);
	}
}

void	ft_expand(char *input_string, int bool_quotes)
{
	char	*tmp;

	tmp = input_string;
	if (ft_strchr(input_string, '$') == NULL)
		return ;
	while (*tmp)
	{
		if (*tmp == '\"')
			bool_quotes = !bool_quotes;
		else if (*tmp == '\'' && !bool_quotes)
		{
			tmp = ft_strchr(tmp + 1, '\'');
			if (ft_strchr(tmp + 1, '$') == NULL)
				return ;
			else
				ft_expand(tmp + 1, 0);
		}
		if (*tmp == '$')
		{
			ft_chunk(input_string, tmp);
			break ;
		}
		else if (*tmp)
			++tmp;
	}
	ft_expand(g_data.aux, 0);
}
