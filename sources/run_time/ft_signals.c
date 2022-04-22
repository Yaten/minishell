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

extern t_shell g_data;

void sigint_handler(int sig)
{
	(void)sig;
	ft_printf("\n%s", prompt.result);
	ft_insert(g_data.array, "?", "130");
}

void here_doc_signal(int sig)
{
	(void)sig;
	ft_insert(g_data.array, "?", "130");
	exit (130);
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
