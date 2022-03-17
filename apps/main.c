/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/17 15:01:36 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_minishell.h"
# include <errno.h>

t_prompt prompt;

/* lida com o Ctrl C */
void sigint_handler(int sig)
{
	(void)sig;
	ft_printf("\n%s", prompt.result);
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

int	main(int argc, char *argv[], char *envp[])
{
	ft_init_signals();
	ft_event_loop(&prompt);
	return (0);
}

// int	main()
// {
// 	t_circular *l;
// 	l = ft_list_create();
// 	ft_list_add_first(l, "carro");
// 	ft_list_add_first(l, "barco");
// 	ft_list_add_first(l, "ave");
// 	ft_list_print(l);
// 	printf("-\n");
// 	ft_list_add_last(l, "zoio");
// 	ft_list_print(l);
// 	printf("-\n");
// 	ft_list_add_first(l, "zero");
// 	ft_list_print(l);
// 	printf("-\n");
// 	ft_list_destroy(&l);
// 	//ft_list_print(l);
// 	return (0);
// }
