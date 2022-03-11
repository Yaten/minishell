/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/11 11:19:13 by wrosendo         ###   ########.fr       */
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
		printf("\n");
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
		if (ft_print_dir(prompt))
			continue ;
		if (ft_set_new_line(prompt))
			continue ;
		// ft_expand(prompt);
	}
}
