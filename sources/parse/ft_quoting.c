/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:02:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/16 18:04:46 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_aux_doubly_quote(char ***aux, int i, int **count_quoting)
{
	g_data.bool_quote = 0;
	if (*(aux[0][0] - 1) == ' ' || *(aux[0][0] + 1) == ' ' || \
	*(aux[0][0] + 1) == '\0')
	{
		if (*(aux[0][0] - 1) == ' ' && *(aux[0][0] + 1) != ' ' && \
		count_quoting[0][0] % 2 == 0 && *(aux[0][0] + 1) != '\0')
			aux[0][0]++;
		else
			g_data.input_string[i++] = *aux[0][0]++;
		if (*(aux[0][0] - 2) != ' ' && *aux[0][0] == ' ' && \
		ft_strchr(aux[0][0], '\"') && count_quoting[0][0] % 2 == 1)
			aux[0][0]++;
	}
	else
	{
		if (*(aux[0][0] - 1) != '\0')
		{
			++aux[0][0];
			g_data.bool_quote = 1;
		}
		else
			g_data.input_string[i++] = *aux[0][0]++;
	}
	ft_doubly_loop(aux, &i);
	return (i);
}

int	ft_aux_simple_quote(char ***aux, int i, int **count_quoting)
{
	g_data.bool_quote = 0;
	if (*(aux[0][0] - 1) == ' ' || *(aux[0][0] + 1) == ' ' || \
	*(aux[0][0] + 1) == '\0')
	{
		if (*(aux[0][0] - 1) == ' ' && *(aux[0][0] + 1) != ' ' && \
		count_quoting[0][0] % 2 == 0)
			aux[0][0]++;
		else
			g_data.input_string[i++] = *aux[0][0]++;
		if (*(aux[0][0] - 2) != ' ' && *aux[0][0] == ' ' && \
		ft_strchr(aux[0][0], '\'') && count_quoting[0][0] % 2 == 1)
			aux[0][0]++;
	}
	else
	{
		if (*(aux[0][0] - 1) != '\0')
		{
			++aux[0][0];
			g_data.bool_quote = 1;
		}
		else
			g_data.input_string[i++] = *aux[0][0]++;
	}
	ft_loop_simple(aux, &i);
	return (i);
}

static int	ft_echo_quoting(char **aux, int i)
{
	int	count_quoting;

	count_quoting = 0;
	if (*aux[0])
	{
		while (!ft_strchr("><|", *aux[0]) && *aux[0] != '\0')
			ft_echo_quoting_loop(&count_quoting, aux, &i);
		return (i);
	}
	return (i);
}

static int	ft_aux_quoting(char **tmp, int i, int bool_quotes)
{
	if (*tmp[0] == '\"')
	{
		bool_quotes = !bool_quotes;
		while (*++tmp[0] != '\"')
			g_data.input_string[i++] = *tmp[0];
		++tmp[0];
		bool_quotes = !bool_quotes;
	}
	else if (*tmp[0] == '\'' && !bool_quotes)
	{
		while (*++tmp[0] != '\'')
			g_data.input_string[i++] = *tmp[0];
		++tmp[0];
	}
	if (*tmp[0])
		g_data.input_string[i++] = *tmp[0]++;
	return (i);
}

void	ft_quoting(int bool_quotes)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = g_data.aux;
	while (*tmp)
	{
		i = ft_echo_quoting(&tmp, i);
		i = ft_aux_quoting(&tmp, i, bool_quotes);
	}
	g_data.input_string[i] = '\0';
}
