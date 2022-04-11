/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:47:58 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/07 21:42:27 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

t_prompt prompt;
extern t_shell g_data;

/* Ctrl C */
void sigint_handler(int sig)
{
	(void)sig;
	ft_printf("\n%s", prompt.result);
	ft_insert(g_data.array, "?", "130");
}

//heredoc signal
void here_doc_signal(int sig)
{
	(void)sig;
	// write(1, "\n", 1);
	ft_insert(g_data.array, "?", "130");
	// puts("");
	exit (130);
	// g_data.here_bol = 0;
	// ft_putstr_fd("\n", 0);
	// close(0);
	// puts("");
	//exit(130);
}

void ft_set_signal(void (*function)(int) , int sig)
{
	void	*function_pointer;

	function_pointer = function;
	signal(sig, function_pointer);
}

void ft_init_signals(void)
{
	ft_set_signal(sigint_handler, SIGINT);
}
