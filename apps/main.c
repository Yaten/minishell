/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/06 17:08:32 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_minishell.h"
# include <errno.h>

t_prompt prompt;

t_shell	g_data;

// static void	init_operators(void);

static void	init_operators(void)
{
	g_data.operators = (char **)ft_calloc(6, sizeof(char *));
	g_data.operators[0] = ft_strdup("|");
	g_data.operators[1] = ft_strdup(">");
	g_data.operators[2] = ft_strdup("<");
	g_data.operators[3] = ft_strdup(">>");
	g_data.operators[4] = ft_strdup("<<");
}

int	main(int argc, char *argv[], char *envp[])
{
	g_data.boll_paths = 1;
	g_data.envp = envp;
	g_data.array = ft_create_table(envp);
	ft_init_signals();
	init_operators();
	ft_event_loop(&prompt);
	return (0);
}
