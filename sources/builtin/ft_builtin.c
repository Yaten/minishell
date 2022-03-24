/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:55:03 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/24 12:39:19 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_builtin()
{
	if (g_data.builtin == 1)
		ft_env();
	if (g_data.builtin == 2)
		ft_pwd();
	if (g_data.builtin == 3)
		ft_echo();
	if (g_data.builtin == 4)
		puts(GREEN"cd: good job!"RESET);
	if (g_data.builtin == 5)
		ft_exit();
	if (g_data.builtin == 6)
		ft_unset();
	if (g_data.builtin == 7)
		ft_export();
}
