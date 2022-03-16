/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubly_linked_list.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:43:35 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/16 20:46:31 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOUBLY_LINKED_LIST
# define FT_DOUBLY_LINKED_LIST

# include "../ft_printf/include/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_doubly_node
{
	char					*val;
	struct s_doubly_node	*prev;
	struct s_doubly_node	*next;
}t_node;

typedef struct	s_doubly
{
	t_node	*begin;
	t_node	*end;
	size_t	size;
}t_doubly;

t_node		*ft_node_create(char *val);

t_doubly	*ft_list_create(void);

void		ft_list_destroy(t_doubly **l_ref);

void		ft_list_add_first(t_doubly *l, char *val);

int			ft_list_is_empty(t_doubly *l);

void		ft_list_print(const t_doubly *l);

void		ft_list_add_last(t_doubly *l, char *val);

#endif
