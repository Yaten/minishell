/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:50:57 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 20:51:22 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_export()
{
	char	*tmp1;
	char	*before;
	char	*last;

	tmp1 = ft_strchr(g_data.node->args[1], '=');
	before = ft_substr(g_data.node->args[1], 0, tmp1 - g_data.node->args[1]);
	last = ft_substr(g_data.node->args[1], tmp1 + 1 - g_data.node->args[1], ft_strlen(g_data.node->args[1]));
	ft_insert(g_data.array, before, last);
	free (before);
	free (last);
}
