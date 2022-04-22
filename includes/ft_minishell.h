/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:27:22 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/16 14:27:2 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_parse.h"
# include "ft_builtin.h"
# include "ft_executor.h"
# include "ft_hash_table.h"
# include "ft_doubly_linked_list.h"
# include "ft_simple_linked_list.h"
# include "../ft_printf/include/ft_printf.h"

# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/history.h>
# include <readline/readline.h>

# define TRUE 1
# define FALSE 0
# define QUOTES "Quotes not paired\n"
# define BACKSLASH "Escape character is not allowed\n"
# define SEMICOLON "Comma is not allowed\n"

# define REDIR_OUTPUT "REDIR_OUTPUT"
# define APPEND_OUTPUT "APPEND_OUTPUT"
# define REDIR_INPUT "REDIR_INPUT"
# define HERE_DOC "HERE_DOC"

# define SEPARATORS " ><\'\"|?$"

# define BLACK "\e[30;1m"
# define RED "\e[31;1m"
# define GREEN "\e[32;1m"
# define YELLOW "\e[33;1m"
# define BLUE "\e[34;1m"
# define MAGENTA "\e[35;1m"
# define CYAN "\e[36;1m"
# define WHITE "\e[37;1m"
# define RESET "\e[0m"

typedef struct s_shell
{
	char		*aux;
	char		**envp;
	char		**operators;
	int			boll_paths;
	int			builtin;
	int			pipe_count;
	t_node		*node;
	t_prompt	prompt;
	t_hash		*array;
	t_doubly	*cmd_table;
	char		*here_doc;
	int			here_bol;
}t_shell;

extern t_shell	g_data;
extern t_prompt prompt;

/**
 * @brief
 *
 * @param input
 * @param prompt
 */
void	ft_event_loop(t_prompt *prompt);

/**
 * @brief
 *
 * @param prompt
 */
void	ft_prompt_concat(t_prompt *prompt);

/**
 * @brief
 *
 * @param prompt
 * @return int
 */
int		ft_set_new_line(t_prompt *prompt);

void	here_doc_signal(int sig);
void	ft_init_signals(void);

# endif
