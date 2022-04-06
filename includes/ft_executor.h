/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:08:15 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/06 11:35:58 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_H
# define FT_EXECUTE_H

# include "ft_doubly_linked_list.h"

void	ft_exececutor(void);

void	ft_exec_sys(t_node *tmp, int *fd_aux);

void	ft_create_heredoc(char *line);

void	ft_dup_in(t_node *tmp, int *fd, int *fd_aux);

void	ft_dup_out(t_node *tmp, int *fd);

#endif
