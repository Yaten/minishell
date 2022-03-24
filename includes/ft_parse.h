/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 21:22:16 by prafael-         ###   ########.fr       */
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

int		ft_find_path(t_node *node);

int		ft_create_cmd(char *line);

void	ft_destroy_list();

int		ft_find_path(t_node *node);

void	ft_pipe(void);

#endif
