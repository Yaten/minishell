/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 17:44:51 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/20 18:57:56 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_split_env(t_hash *array, char *envp[])
{
	int		j;
	char	*last;
	char	*tmp1;
	char	*before;

	j = -1;
	while (envp[++j])
	{
		tmp1 = ft_strchr(envp[j], '=');
		before = ft_substr(envp[j], 0, tmp1 - envp[j]);
		last = ft_substr(envp[j], tmp1 + 1 - envp[j], ft_strlen(envp[j]));
		ft_insert(array, before, last);
		free (before);
		free (last);
	}
	return (0);
}
