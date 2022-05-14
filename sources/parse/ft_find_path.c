/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/14 14:50:13 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int	ft_find_path(char *aux)
{
	int		i;
	char	*tmp;
	char	*path;
	char	**paths;
	char	*path_slash;

	i = -1;
	tmp = ft_find_value("PATH");
	paths = ft_split(tmp, ':');
	while (paths != NULL && paths[++i])
	{
		path_slash = ft_strjoin(paths[i], "/");
		free(paths[i]);
		path = ft_strjoin(path_slash, aux);
		free(path_slash);
		if (!access(path, F_OK | X_OK))
		{
			while (paths[++i])
				free(paths[i]);
			free(paths);
			g_data.cmd_table->end->path = path;
			return (1);
		}
		free(path);
	}
	free(paths);
	return (0);
}
