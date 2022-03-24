/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 20:51:14 by prafael-         ###   ########.fr       */
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
	while (TRUE)
	{
		ft_prompt_concat(prompt);
		if (ft_print_dir(prompt) || ft_set_new_line(prompt))
			continue ;
		ft_parse(prompt->input_string, g_data.envp);
	}
}
