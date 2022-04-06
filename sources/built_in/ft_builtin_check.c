/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/06 10:27:36 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

// int		ft_builtin_check()
// {
// 	//if(!(ft_strcmp(cmd->args[0], "cmd", 3)))
// 	if(g_data.node->args[0] == NULL)
// 		return (g_data.builtin = FALSE);
// 	if(!(ft_strncmp(g_data.node->args[0], "cd", 2)))
// 		return (g_data.builtin = 1);
// 	if(!(ft_strncmp(g_data.node->args[0], "env", 3)))
// 		return (g_data.builtin = 2);
// 	if(!(ft_strncmp(g_data.node->args[0], "pwd", 3)))
// 		return (g_data.builtin = 3);
// 	if(!(ft_strncmp(g_data.node->args[0], "echo", 4)))
// 		return (g_data.builtin = 4);
// 	if(!(ft_strncmp(g_data.node->args[0], "exit", 4)))
// 		return (g_data.builtin = 5);
// 	if(!(ft_strncmp(g_data.node->args[0], "unset", 5)))
// 		return (g_data.builtin = 6);
// 	if(!(ft_strncmp(g_data.node->args[0], "export", 6)))
// 		return (g_data.builtin = 7);
// 	return (g_data.builtin = FALSE);
// }

int		ft_builtin_check(char *aux)
{
	//if(!(ft_strcmp(cmd->args[0], "cmd", 3)))
	if(aux == NULL)
		return (g_data.cmd_table->end->is_buildin = FALSE);
	if(!(ft_strncmp(aux, "cd", 2)))
		return (g_data.cmd_table->end->is_buildin = 4);
	if(!(ft_strncmp(aux, "exit", 4)))
		return (g_data.cmd_table->end->is_buildin = 5);
	if(!(ft_strncmp(aux, "unset", 5)))
		return (g_data.cmd_table->end->is_buildin = 6);
	if(!(ft_strncmp(aux, "export", 6)))
		return (g_data.cmd_table->end->is_buildin = 7);
	return (g_data.cmd_table->end->is_buildin = FALSE);
}
