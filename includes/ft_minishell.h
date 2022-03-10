/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:27:22 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/10 10:20:42 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

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
}t_prompt;

/**
 * @brief
 *
 * @param input
 * @param prompt
 */
void	ft_event_loop(char *input, t_prompt *prompt);

/**
 * @brief
 *
 * @param prompt
 */
void	ft_prompt_concat(t_prompt *prompt);

# endif
