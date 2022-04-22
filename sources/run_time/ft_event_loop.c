/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/20 16:31:33 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

static int	ft_clean_program(t_prompt *prompt)
{
	int		i;

	i = -1;
	ft_printf("\n");
	ft_destroy_hash(g_data.array);
	while (g_data.operators[++i])
		free(g_data.operators[i]);
	free(g_data.operators);
    (void)prompt;
	exit(0);
}

int	ft_print_dir(t_prompt *prompt)
{
	char	*buf;

	buf = readline(prompt->result);
	free(prompt->result);
	if (!buf)
		ft_clean_program(prompt);
	if (*buf)
	{
		add_history(buf);
		ft_strlcpy(prompt->input_string, buf, MAXINPUT);
		free(buf);
        buf = NULL;
		return (0);
	}
	else
    {
        free(buf);
		return (1);
    }
}

void	ft_event_loop(t_prompt *prompt)
{
	while (TRUE)
	{
		ft_prompt_concat(prompt);
		if (ft_print_dir(prompt) || ft_set_new_line(prompt))
			continue ;
		g_data.aux = prompt->input_string;
		ft_expand(g_data.aux, 0);
		ft_quoting(prompt, g_data.aux, 0);
		if (!ft_tokenize(prompt))
    		continue ;
		g_data.cmd_table = ft_list_create();
		ft_parse(prompt->input_string, g_data.envp);
		ft_list_destroy(&g_data.cmd_table);
	}
}
