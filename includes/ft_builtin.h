/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:43:47 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/24 21:15:02 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILTIN_H
# define FT_BUILTIN_H

/**
 * @brief
 *
 */
void	ft_builtin();

/**
 * @brief
 *
 * @return int
 */
int		ft_builtin_path();

/**
 * @brief
 *
 * @param node
 * @return int
 */
int		ft_builtin_check(t_node *node);

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

void	ft_export(void);

int		ft_exit();

void	ft_echo();

void	ft_cd();

#endif
