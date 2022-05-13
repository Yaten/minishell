/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/12 20:20:34 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_minishell.h"
#include <errno.h>

t_shell	g_data;

int	main(int argc, char *argv[], char *envp[])
{
	g_data.array = ft_create_table(envp);
	g_data.envp = envp;
	ft_init_signals();
	ft_event_loop();
	return (0);
}
