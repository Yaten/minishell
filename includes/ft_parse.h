/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/05/11 23:42:50 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# include "ft_doubly_linked_list.h"

typedef struct s_var_path
{
	int		i;
	int		check_bin_path;
	char	*tmp;
	char	*path;
	char	**paths;
	char	*path_slash;
}t_var_path;

void	ft_parse(void);
int		ft_syntax(void);
int		ft_tokenize(void);
void	ft_destroy_list(void);
int		ft_find_path(char *aux);
void	ft_quoting(int bool_quotes);
void	ft_create_cmd(t_node *begin, t_node *end);
t_node	*ft_open_files(t_node *begin, t_node *node);
void	ft_expand(char *input_string, int bool_quotes);
int		ft_count_word(t_node *begin);

#endif
