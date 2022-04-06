/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:44:02 by wrosendo          #+#    #+#             */
/*   Updated: 2022/04/06 11:11:21 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_builtin_path(char *aux)
{
	char	*tmp;

	tmp = ft_strrchr(aux, '/');
	if(aux == NULL)
		return (g_data.cmd_table->end->is_buildin = FALSE);
	if(!(ft_strncmp(tmp + 1, "env", 3)))
		return (g_data.cmd_table->end->is_buildin = 1);
	if(!(ft_strncmp(tmp + 1, "pwd", 3)))
		return (g_data.cmd_table->end->is_buildin = 2);
	if(!(ft_strncmp(tmp + 1, "echo", 4)))
		return (g_data.cmd_table->end->is_buildin = 3);
	return (g_data.cmd_table->end->is_buildin = FALSE);
}
