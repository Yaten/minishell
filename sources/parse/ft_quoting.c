/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:02:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/26 16:37:03 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_quoting(t_prompt *prompt, char *input_string, int bool_quotes)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = input_string;
	while (*tmp)
	{
		if (*tmp == '\"')
		{
			bool_quotes = !bool_quotes;
			tmp++;
			while (*tmp != '\"')
			{
				prompt->input_string[i++] = *tmp;
				tmp++;
			}
			tmp++;
			bool_quotes = !bool_quotes;
		}
		else if (*tmp == '\'' && !bool_quotes)
		{
			tmp++;
			while (*tmp != '\'')
			{
				prompt->input_string[i++] = *tmp;
				tmp++;
			}
			tmp++;
		}
		if (*tmp)
		{
			prompt->input_string[i++] = *tmp;
			tmp++;
		}
	}
	prompt->input_string[i] = '\0';
}
