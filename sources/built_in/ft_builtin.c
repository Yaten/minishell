/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:55:03 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/06 11:24:36 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_builtin(t_node *tmp)
{
	if (tmp->is_buildin == 1)
		ft_env();
	if (tmp->is_buildin == 2)
		ft_pwd();
	if (tmp->is_buildin == 3)
		ft_echo(tmp);
	if (tmp->is_buildin == 4)
		ft_cd();
	if (tmp->is_buildin == 5)
		ft_exit();
	if (tmp->is_buildin == 6)
		ft_unset();
	if (tmp->is_buildin == 7)
		ft_export(tmp);
}
