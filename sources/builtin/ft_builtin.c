/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:55:03 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 17:56:36 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_builtin()
{
	if (g_data.builtin == 1)
		puts(GREEN"cd: good job!"RESET);
	if (g_data.builtin == 2)
		puts(GREEN"env: good job!"RESET);
	if (g_data.builtin == 3)
		ft_pwd();
	if (g_data.builtin == 4)
		puts(GREEN"echo: good job!"RESET);
	if (g_data.builtin == 5)
		puts(GREEN"exit: good job!"RESET);
	if (g_data.builtin == 6)
		puts(GREEN"unset: good job!"RESET);
	if (g_data.builtin == 7)
		puts(GREEN"export: good job!"RESET);
}