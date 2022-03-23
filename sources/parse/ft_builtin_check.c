/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 16:11:35 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int		ft_builtin_check()
{
	//if(!(ft_strcmp(cmd->args[0], "cmd", 3)))
	if(g_data.node == NULL)
		return (g_data.builtin = FALSE);
	if(!(ft_strcmp(g_data.node[0], "cd", 2)))
		return (g_data.builtin = TRUE);
	if(!(ft_strcmp(g_data.node[0], "env", 3)))
		return (g_data.builtin = TRUE);
	if(!(ft_strcmp(g_data.node[0], "pwd", 3)))
		return (g_data.builtin = TRUE);
	if(!(ft_strcmp(g_data.node[0], "echo", 4)))
		return (g_data.builtin = TRUE);
	if(!(ft_strcmp(g_data.node[0], "exit", 4)))
		return (g_data.builtin = TRUE);
	if(!(ft_strcmp(g_data.node[0], "unset", 5)))
		return (g_data.builtin = TRUE);
	if(!(ft_strcmp(g_data.node[0], "export", 6)))
		return (g_data.builtin = TRUE);
	return (g_data.builtin = FALSE);
}
