/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/11 22:10:04 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include "ft_doubly_linked_list.h"

void	ft_parse(void);
int		ft_find_path(char *aux);
void	ft_create_cmd(t_node *begin, t_node *end);
void	ft_destroy_list(void);
void	ft_expand(char *input_string, int bool_quotes);
void	ft_quoting(int bool_quotes);
int		ft_tokenize(void);
int		ft_syntax(void);
t_node	*ft_open_files(t_node *begin, t_node *node);

#endif
