/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:02:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/05/11 18:44:52 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_quoting(int bool_quotes)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = g_data.input_string;
	while (*tmp)
	{
		if (*tmp == '\"')
		{
			bool_quotes = !bool_quotes;
			while (*++tmp != '\"')
				g_data.input_string[i++] = *tmp;
			++tmp;
			bool_quotes = !bool_quotes;
		}
		else if (*tmp == '\'' && !bool_quotes)
		{
			while (*++tmp != '\'')
				g_data.input_string[i++] = *tmp;
			++tmp;
		}
		if (*tmp)
			g_data.input_string[i++] = *tmp++;
	}
	g_data.input_string[i] = '\0';
}
