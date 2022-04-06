/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:43:47 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/06 11:22:42 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

#include "ft_doubly_linked_list.h"

/**
 * @brief
 *
 * @param tmp
 */
void	ft_builtin(t_node *tmp);

/**
 * @brief
 *
 * @return int
 */
int		ft_builtin_path(char *aux);

/**
 * @brief
 *
 * @param node
 * @return int
 */
int		ft_builtin_check(char *aux);

/**
 * @brief
 *
 * @return int
 */
int		ft_pwd(void);

/**
 * @brief
 *
 * @return int
 */
void	ft_env(void);

void	ft_unset(void);

void	ft_export(t_node *tmp);

int		ft_exit();

void	ft_echo(t_node *tmp);

void	ft_cd();

#endif
