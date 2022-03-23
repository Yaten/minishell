/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/22 19:20:55 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

typedef struct s_node
{
	char			**args;
	char			*relation;
	int				fd_in;
	int				fd_out;
	struct s_node	*next;
}					t_node;

void	ft_parse(char *line, char **envp);

#endif
