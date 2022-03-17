/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/17 15:18:38 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE
# define FT_PARSE
# include <stdio.h>

#define PARSE_DELIMITER " \t\n\r\a"
#define PARSE_BUFFSIZE 64
#define SINGLE_QUOTE '\''
#define DOUBLE_QUOTE '"'

typedef struct s_cmd
{
	char				**args;
	char				*relation;
	int					input;
	int					output;
	int					builtin;
	struct simple_cmd	*prev;
	struct simple_cmd	*next;
}						t_cmd;

typedef struct	s_circular
{
	t_cmd	*head;
	t_cmd	*tail;
	size_t	size;
}						t_circular;

void		*ft_cmd_create(t_cmd *new_cmd);

t_circular	*ft_list_create(void);

void		ft_list_destroy(t_circular **l_ref);

void		ft_list_add_first(t_circular *l, char *val);

int			ft_list_is_empty(t_circular *l);

void		ft_list_print(const t_circular *l);

void		ft_list_add_last(t_circular *l, char *val);

#endif