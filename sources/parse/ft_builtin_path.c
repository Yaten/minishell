/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:44:02 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/24 12:39:26 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_builtin_path()
{
	char	*tmp;

	tmp = ft_strrchr(g_data.node->args[0], '/');
	if(g_data.node->args[0] == NULL)
		return (g_data.builtin = FALSE);
	if(!(ft_strncmp(tmp + 1, "env", 3)))
		return (g_data.builtin = 1);
	if(!(ft_strncmp(tmp + 1, "pwd", 3)))
		return (g_data.builtin = 2);
	if(!(ft_strncmp(tmp + 1, "echo", 4)))
		return (g_data.builtin = 3);
	return (g_data.builtin = FALSE);
}
