/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/27 21:37:07 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_find_path(char *aux)
{
	char	**paths;
	char	*path;
	char	*path_slash;
	int		i;

	// paths = ft_split(ft_find_value("PATH"), ':');
	i = -1;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[++i])
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
			free(aux);
			aux = path;
			g_data.cmd_table->end->path = path;
			return (1);
		}
		free(path);
	}
	free(paths);
	return (0);
}
