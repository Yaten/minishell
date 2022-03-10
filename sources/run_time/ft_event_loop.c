/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/10 17:07:45 by rsiqueir         ###   ########.fr       */
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
		// printf("depois do if: %s\n", getenv("USER"));
	}
}
