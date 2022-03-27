/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:53:01 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/03/23 21:20:59 by prafael-         ###   ########.fr       */
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
	ft_pipe();
	(void)envp;
}
