/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/10 10:20:48 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_prompt	prompt;
	char		input[MAXINPUT];

	ft_event_loop(input, &prompt);
	return (0);
}
