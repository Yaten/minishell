/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/09 16:34:30 by wrosendo         ###   ########.fr       */
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
	t_doubly	*token;

	/* token = ft_list_create(); */
	while (TRUE)
	{
		/*
		 * t_doubly	*token;
		*/
		ft_prompt_concat(prompt);
		if (ft_print_dir(prompt) || ft_set_new_line(prompt))
			continue ;
		g_data.aux = prompt->input_string;
		ft_expand(g_data.aux, 0);
		ft_quoting(prompt, g_data.aux, 0);
        token = ft_list_create();
		if (!ft_tokenize(prompt, token))
    		continue ;
		g_data.cmd_table = ft_list_create();
		ft_parse(token);
		/* ft_list_destroy(&g_data.cmd_table); */
		/* ft_list_destroy(&token); */
		/*
			* free(token);
			* token = NULL;
			*/
	}
}
