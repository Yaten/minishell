/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:02:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/08/02 21:05:26 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	ft_echo_quoting(char *aux, int i)
{
	if (aux)
	{
		while (!ft_strchr("><|", *aux) && *aux != '\0')
		{
			if (*aux == '\"')
			{
				g_data.input_string[i++] = *aux++;
				while (*aux != '\"')
					g_data.input_string[i++] = *aux++;
			}
			else if (*aux == '\'')
			{
				g_data.input_string[i++] = *aux++;
				while (*aux != '\'')
					g_data.input_string[i++] = *aux++;
			}
			g_data.input_string[i++] = *aux++;
		}
		if (*aux == '\0')
			return (0);
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
	char	*aux;

	i = 0;
	tmp = g_data.aux;
	aux = ft_strnstr(g_data.aux, "echo", ft_strlen(g_data.aux));
	while (*tmp)
	{
		if (tmp == aux)
		{
			i = ft_echo_quoting(aux, i);
			if (!i)
				return ;
		}
		i = ft_aux_quoting(&tmp, i, bool_quotes);
	}
	g_data.input_string[i] = '\0';
}
