/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:08:15 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/05 09:40:03 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_H
# define FT_EXECUTE_H

# include "ft_doubly_linked_list.h"

void	ft_exececutor(void);

void	ft_exec_sys(t_node *tmp, int *fd_aux);

void	ft_create_heredoc(char *line);

#endif
