/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/26 16:11:26 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_print_dir(t_prompt *prompt)
{
	char	*buf;
	int		i;

	buf = readline(prompt->result);
	free(prompt->result);
	if (!buf)
	{
		ft_printf("\n");
		ft_destroy_hash(g_data.array);

		i = -1;
		while (g_data.operators[++i])
			free(g_data.operators[i]);
		free(g_data.operators);

		// i = -1;
		// while (g_data.node->args[++i])
		// 	free(g_data.node->args[i]);
		// free(g_data.node->args);

		puts("sai do programa");
		exit(0);
	}
	if (ft_strlen(buf) != 0)
	{
		add_history(buf);
		ft_strlcpy(prompt->input_string, buf, MAXINPUT);
		free(buf);
		return (0);
	}
	else
		return (1);
}

void	ft_event_loop(t_prompt *prompt)
{
	// ft_prompt_concat(prompt);
	while (TRUE)
	{
		ft_prompt_concat(prompt);
		if (ft_print_dir(prompt) || ft_set_new_line(prompt))
			continue ;
		// g_data.aux = prompt->input_string;
		// ft_expand(g_data.aux, 0);
		// printf("temp: %s\n", g_data.aux);
		// ft_quoting(prompt, g_data.aux, 0);
		// printf("without quotes: %s\n", prompt->input_string);
		g_data.cmd_table = ft_list_create();
		ft_parse(prompt->input_string, g_data.envp);
		ft_list_destroy(&g_data.cmd_table);
	}
}
