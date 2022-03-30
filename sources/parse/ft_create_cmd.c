/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/30 14:26:40 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

// void	ft_check_operators(char *line)
// {

// }

int	ft_create_cmd(char *line)
{
	if (ft_strchr(line, '>'))
	{
		ft_create_redir_output(line);
		ft_redir();
	}
	else
		return(ft_create_pipe(line));
	// ft_check_operators(line);

	return (0);
}
