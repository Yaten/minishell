/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 07:25:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 20:51:17 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

char	*ft_expand_last(char *tmp)
{
	while (*tmp && !ft_strchr(SEPARATORS, *tmp))
		++tmp;
	return (tmp);
}

char	*ft_getvalue(char *value)
{
	char *content;

	content = getenv((value));
	if (!content)
		return ("");
	return (content);
}

void	ft_chunk(t_prompt *prompt, char *tmp)
{
	char	*first;
	char	*last;
	char	*middle;
	char	*former;
	// char	*latter;
	char	*aux;

	first = ft_substr(prompt->input_string, 0, tmp - prompt->input_string);
	last = ft_expand_last(tmp + 1);
	middle = ft_substr(prompt->input_string, tmp + 1 - prompt->input_string, last - tmp - 1);
	middle = ft_getvalue(middle);
	last = ft_strdup(last);
	former = ft_strjoin(first, middle);
	aux = ft_strjoin(former, last);
	g_data.aux = ft_strdup(aux);
	// return (aux);
	// printf("temporario: %s\n", aux);
}

void	ft_expand(t_prompt *prompt, int bool_quotes)
{
	char	*tmp;
	//char	*tmp2;

	tmp = prompt->input_string;
	while (*tmp)
	{
		if (*tmp == '\"')
			bool_quotes = !bool_quotes;
		else if (*tmp == '\'' && !bool_quotes)
			tmp = ft_strchr(tmp + 1, '\'');
		if (*tmp == '$')
		{
			ft_chunk(prompt, tmp);
			++tmp;
		}
		else if (*tmp)
			++tmp;
	}
	if (g_data.aux == NULL)
		printf("temporario: %s\n", prompt->input_string);
	else
		printf("temporario: %s\n", g_data.aux);
	free (g_data.aux);
	g_data.aux = NULL;
	// printf("temporario 2: %s\n", prompt->input_string);
	// (void)tmp2;
}
