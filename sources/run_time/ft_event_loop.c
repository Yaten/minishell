/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/10 10:12:16 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_print_dir(char *input, t_prompt *prompt)
{
	char	*buf;

	buf = readline(prompt->result);
	if (ft_strlen(buf) != 0)
	{
		add_history(buf);
		ft_strlcpy(input, buf, ft_strlen(input));
		return (0);
	}
	else
		return (1);
}

void	ft_event_loop(char *input, t_prompt *prompt)
{
	while (TRUE)
	{
		ft_prompt_concat(prompt);
		if (ft_print_dir(input, prompt))
			continue ;
		// printf("depois do if: %s\n", getenv("USER"));
	}
	(void)input;
}
