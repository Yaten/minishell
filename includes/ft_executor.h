/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:08:15 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/04 11:17:28 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXECUTE_H
# define FT_EXECUTE_H

# include "ft_doubly_linked_list.h"

void	ft_exececutor(void);

void	ft_redir(void);

void	ft_exec_sys(t_node *tmp, int *fd_aux);

void	ft_create_heredoc(char *line);

#endif
