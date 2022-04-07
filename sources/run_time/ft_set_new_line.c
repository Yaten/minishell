/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_new_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:04:17 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/07 18:19:06 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_error_handler(t_prompt *prompt, char *message)
{
	ft_putstr_fd(prompt->input_string, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (!ft_strncmp(message, QUOTES, ft_strlen(message)))
		ft_putstr_fd(QUOTES, STDERR_FILENO);
	else if (!ft_strncmp(message, BACKSLASH, ft_strlen(message)))
		ft_putstr_fd(BACKSLASH, STDERR_FILENO);
	else if (!ft_strncmp(message, SEMICOLON, ft_strlen(message)))
		ft_putstr_fd(SEMICOLON, STDERR_FILENO);
}

int	ft_quotes(t_prompt *prompt)
{
	char	*tmp;

	tmp = prompt->input_string;
	while (*tmp)
	{
		if (*tmp == '\"')
			tmp = ft_strchr(tmp + 1, '\"');
		if (tmp == NULL)
		{
			ft_error_handler(prompt, QUOTES);
			return (FALSE);
		}
		if (*tmp == '\'')
			tmp = ft_strchr(tmp + 1, '\'');
		if (tmp == NULL)
		{
			ft_error_handler(prompt, QUOTES);
			return (FALSE);
		}
		++tmp;
	}
	return (TRUE);
}

int	ft_backslash_semicolon(t_prompt *prompt)
{
	char	*tmp;

	tmp = prompt->input_string;
	while (*tmp)
	{
		if (*tmp == '\\')
		{
			ft_error_handler(prompt, BACKSLASH);
			return (FALSE);
		}
		if (*tmp == ';')
		{
			ft_error_handler(prompt, SEMICOLON);
			return (FALSE);
		}
		++tmp;
	}
	return (TRUE);
}

int	ft_set_new_line(t_prompt *prompt)
{
	if (!ft_quotes(prompt) || !ft_backslash_semicolon(prompt))
		return (TRUE);
	else
		return (FALSE);
}
