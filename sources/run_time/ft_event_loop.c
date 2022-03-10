/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:46:25 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/10 12:30:55 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

int	ft_print_dir(t_prompt *prompt)
{
	char	*buf;

	buf = readline(prompt->result);
	free(prompt->result);
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

static void sigint_handler(int sig, t_prompt *prompt)
{
	static t_prompt *prompt_pointer;
	
	if (sig == -1)
		prompt_pointer = prompt;
	else
		printf("\n%s", prompt_pointer->result);
}


void	ft_event_loop(t_prompt *prompt)
{
	void	*function_pointer;

	function_pointer = sigint_handler;
	signal(SIGINT, function_pointer);
	while (TRUE)
	{
		ft_prompt_concat(prompt);
		sigint_handler(-1, prompt);
		if (ft_print_dir(prompt))
			continue ;
		// printf("depois do if: %s\n", getenv("USER"));
	}
}
