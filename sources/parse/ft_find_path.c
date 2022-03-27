/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:41:44 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 20:57:24 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_find_path(char *aux)
{
	char	**paths;
	char	*path;
	char	*path_slash;
	int		i;

	paths = ft_split(ft_find_value("PATH"), ':');

	i = -1;
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
