/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:04:17 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/10 18:38:12 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_error_handler(char *message)
{
	ft_putstr_fd(g_data.input_string, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (!ft_strncmp(message, QUOTES, ft_strlen(message)))
		ft_putstr_fd(QUOTES, STDERR_FILENO);
	else if (!ft_strncmp(message, BACKSLASH, ft_strlen(message)))
		ft_putstr_fd(BACKSLASH, STDERR_FILENO);
	else if (!ft_strncmp(message, SEMICOLON, ft_strlen(message)))
		ft_putstr_fd(SEMICOLON, STDERR_FILENO);
}

int	ft_quotes()
{
	char	*tmp;

	tmp = g_data.input_string;
	while (*tmp)
	{
		if (*tmp == '\"')
			tmp = ft_strchr(tmp + 1, '\"');
		if (tmp == NULL)
		{
			ft_error_handler(QUOTES);
			return (FALSE);
		}
		if (*tmp == '\'')
			tmp = ft_strchr(tmp + 1, '\'');
		if (tmp == NULL)
		{
			ft_error_handler(QUOTES);
			return (FALSE);
		}
		++tmp;
	}
	return (TRUE);
}

int	ft_backslash_semicolon()
{
	char	*tmp;

	tmp = g_data.input_string;
	while (*tmp)
	{
		if (*tmp == '\\')
		{
			ft_error_handler(BACKSLASH);
			return (FALSE);
		}
		if (*tmp == ';')
		{
			ft_error_handler(SEMICOLON);
			return (FALSE);
		}
		++tmp;
	}
	return (TRUE);
}

int	ft_set_new_line()
{
	if (!ft_quotes() || !ft_backslash_semicolon())
		return (TRUE);
	else
		return (FALSE);
}
