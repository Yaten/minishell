/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_linked_list.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:31:25 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/29 15:10:27 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLE_LINKED_LIST_H
# define FT_SIMPLE_LINKED_LIST_H

typedef struct s_snode
{
	char			*val;
	struct s_snode	*next;
}t_snode;

typedef struct s_slist
{
	int		size;
	t_snode	*begin;
	t_snode	*end;
}t_slist;

/**
 * @brief
 *
 * @param l_ref
 */
void	ft_slist_destroy(t_slist **l_ref);

/**
 * @brief
 *
 * @return t_slist*
 */
t_slist	*ft_slinkedlist_create(void);

/**
 * @brief
 *
 * @param l
 * @param val
 */
void	ft_slist_add_last(t_slist *l, char *val);

/**
 * @brief
 *
 * @param l
 * @return int
 */
int		ft_slist_is_empty(t_slist *l);

/**
 * @brief
 *
 * @param l
 */
void	ft_slist_print(const t_slist *l);

/**
 * @brief
 *
 * @param value
 * @return t_snode*
 */
t_snode	*ft_snode_create(char *value);

#endif
