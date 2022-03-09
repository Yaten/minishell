/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:27:22 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/09 15:33:26 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_prompt {

    char *user;
    char *hostname;
    char *path;
    
}               t_prompt;



void	ft_event_loop(char *input);

# endif
