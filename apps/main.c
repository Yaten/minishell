/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/11 18:23:33 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"
#include <errno.h>

t_shell	g_data;

int	main(int argc, char *argv[], char *envp[])
{
	g_data.boll_paths = 1;
	g_data.envp = envp;
	g_data.array = ft_create_table(envp);
	ft_init_signals();
	ft_event_loop();
	return (0);
}
