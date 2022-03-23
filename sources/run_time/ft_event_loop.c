/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/22 20:17:28 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_print_dir(t_prompt *prompt)
{
	char	*buf;

	buf = readline(prompt->result);
	free(prompt->result);
	if (!buf)
	{
		ft_printf("\n");
		// ft_destroy_hash(g_data.array);
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

// char *ft_expand(char *variable)
// {
// 	char *content;
// 	content = getenv((variable + 1));
// 	if (!content)
// 		return ("");
// 	return (content);
// }

void	ft_event_loop(t_prompt *prompt)
{
	while (TRUE)
	{
		ft_prompt_concat(prompt);
		if (ft_print_dir(prompt) || ft_set_new_line(prompt))
			continue ;
		ft_parse(prompt->input_string, g_data.envp);
		// ft_expand(prompt, FALSE);
	}
}
