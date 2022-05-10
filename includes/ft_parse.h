/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/09 22:41:56 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include "ft_doubly_linked_list.h"

# define MAXINPUT 1024

typedef struct s_prompt
{
	char	*user;
	char	*hostname;
	char	*path;
	char	*result;
	char	*cmd;
	char	input_string[MAXINPUT];
}t_prompt;

void	ft_parse(t_doubly *token);

int		ft_find_path(char *aux);

void	ft_create_cmd(t_node *begin, t_node *end);

void	ft_destroy_list(void);

void	ft_expand(char *input_string, int bool_quotes);

void	ft_quoting(t_prompt *prompt, char *input_string, int bool_quotes);

int		ft_tokenize(t_prompt *prompt, t_doubly *token);

int		ft_syntax(t_doubly *token);

t_node	*ft_open_files(t_node *begin, t_node *node);

#endif
