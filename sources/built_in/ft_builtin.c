/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:55:03 by prafael-          #+#    #+#             */
/*   Updated: 2022/08/17 13:18:06 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_builtin(t_node *tmp)
{
	int	i;

	i = 0;
	if (tmp->is_builtin == 1)
		i = ft_env(tmp);
	if (tmp->is_builtin == 2)
		ft_pwd();
	if (tmp->is_builtin == 3)
		ft_echo(tmp);
	if (tmp->is_builtin == 4)
		ft_cd();
	if (tmp->is_builtin == 5)
		ft_exit();
	if (tmp->is_builtin == 6)
		ft_unset();
	if (tmp->is_builtin == 7)
		ft_export(tmp);
	return (i);
}
