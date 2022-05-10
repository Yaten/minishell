/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/10 15:30:56 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_builtin_check(char *aux)
{
	if (aux == NULL)
		return (g_data.cmd_table->end->is_builtin = FALSE);
	if (!(ft_strncmp(aux, "cd", 2)))
		return (g_data.cmd_table->end->is_builtin = 4);
	if (!(ft_strncmp(aux, "exit", 4)))
		return (g_data.cmd_table->end->is_builtin = 5);
	if (!(ft_strncmp(aux, "unset", 5)))
		return (g_data.cmd_table->end->is_builtin = 6);
	if (!(ft_strncmp(aux, "export", 6)))
		return (g_data.cmd_table->end->is_builtin = 7);
	return (g_data.cmd_table->end->is_builtin = FALSE);
}
