/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:27:22 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/10 12:03:12 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define MAXINPUT 1024
# define BLACK "\e[30;1m"
# define RED "\e[31;1m"
# define GREEN "\e[32;1m"
# define YELLOW "\e[33;1m"
# define BLUE "\e[34;1m"
# define MAGENTA "\e[35;1m"
# define CYAN "\e[36;1m"
# define WHITE "\e[37;1m"

typedef struct	s_prompt
{
	char	*user;
	char	*hostname;
	char	*path;
	char	*result;
	char	input_string[MAXINPUT];
}t_prompt;

/**
 * @brief
 *
 * @param input
 * @param prompt
 */
void	ft_event_loop(t_prompt *prompt);

/**
 * @brief
 *
 * @param prompt
 */
void	ft_prompt_concat(t_prompt *prompt);

# endif
