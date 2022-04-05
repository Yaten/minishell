/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:53:01 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/04/04 17:50:28 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_parse(char *line, char **envp)
{
	int	index;

	index = 0;
	g_data.pipe_count = 0;
	while(line[index] != '\0')
	{
		if (line[index] == '|')
		{
			line[index] = '\0';
			ft_create_cmd(line);
			line += index + 1;
			index = 0;
			g_data.pipe_count++;
		}
		index++;
	}
	if (!ft_create_cmd(line))
		return ;
	if (g_data.boll_paths)
		ft_exececutor();
	else
		ft_putstr_fd("commando not found\n", 2);
	(void)envp;
}
