/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 02:59:07 by user42            #+#    #+#             */
/*   Updated: 2022/08/16 18:11:43 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_loop_simple(char ***aux, int *i)
{
	while (*aux[0][0] != '\0' && *aux[0][0] != '\'')
	{
		if (*aux[0][0] == '\'' && *(aux[0][0] + 1) == '\'')
		{
			aux[0][0] = aux[0][0] + 2;
			while (*aux[0][0] != '\0' && *aux[0][0] != '\'')
				g_data.input_string[(*i)++] = *aux[0][0]++;
		}
		else
		{
			if (*aux[0][0] == ' ' && g_data.bool_quote)
				break ;
			else
				g_data.input_string[(*i)++] = *aux[0][0]++;
		}
	}
	if (g_data.bool_quote)
		g_data.input_string[*i++] = '\"';
	return (*i);
}

int	ft_doubly_loop(char ***aux, int *i)
{
	while (*aux[0][0] != '\0' && *aux[0][0] != '\"')
	{
		if (*aux[0][0] == '\"' && *(aux[0][0] + 1) == '\"')
		{
			aux[0][0] = aux[0][0] + 2;
			while (*aux[0][0] != '\0' && *aux[0][0] != '\"')
				g_data.input_string[(*i)++] = *aux[0][0]++;
		}
		else
		{
			if (*aux[0][0] == ' ' && g_data.bool_quote)
				break ;
			else
				g_data.input_string[(*i)++] = *aux[0][0]++;
		}
	}
	if (g_data.bool_quote)
		g_data.input_string[*i++] = '\"';
	return (*i);
}

void	ft_echo_quoting_loop(int *count_quoting, char **aux, int *i)
{
	if (*aux[0] == '\"')
	{
		*count_quoting = *count_quoting + 1;
		if (*(aux[0] + 1) == '\"')
		{
			while (*aux[0] == '\"')
				++aux[0];
		}
		else
			*i = ft_aux_doubly_quote(&aux, *i, &count_quoting);
	}
	else if (*aux[0] == '\'')
	{
		*count_quoting = *count_quoting + 1;
		if (*(aux[0] + 1) == '\'')
		{
			while (*aux[0] == '\'')
				++aux[0];
		}
		else
			*i = ft_aux_simple_quote(&aux, *i, &count_quoting);
	}
	else
		g_data.input_string[(*i)++] = *aux[0]++;
}
