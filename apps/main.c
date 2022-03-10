/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/10 12:02:36 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_minishell.h"



int	main(int argc, char *argv[], char *envp[])
{
	t_prompt	prompt;

	ft_event_loop(&prompt);
	return (0);
}
