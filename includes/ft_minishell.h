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

# include "../ft_printf/include/ft_printf.h"
# include "ft_parse.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define TRUE 1
# define FALSE 0
# define MAXINPUT 1024
# define QUOTES "Quotes not paired\n"
# define BACKSLASH "Escape character is not allowed\n"
# define SEMICOLON "Comma is not allowed\n"

# define SEPARATORS " ><\'\"|?$"

# define BLACK "\e[30;1m"
# define RED "\e[31;1m"
# define GREEN "\e[32;1m"
# define YELLOW "\e[33;1m"
# define BLUE "\e[34;1m"
# define MAGENTA "\e[35;1m"
# define CYAN "\e[36;1m"
# define WHITE "\e[37;1m"
# define Reset "\e[0m"

typedef struct	s_prompt
{
	char	*user;
	char	*hostname;
	char	*path;
	char	*result;
	char	*cmd;
	char	input_string[MAXINPUT];
}t_prompt;


typedef struct Ht_item Ht_item;
// Define the hash table item here
struct Ht_item
{
	char	*key;
	char	*value;
};
//Hash table has an array of pointers which themselves point to Ht_item, so it is a double-pointer

typedef struct LinkedList LinkedList;
// Define the Linkedlisthere
struct LinkedList
{
	Ht_item		*item;
	LinkedList	*next;
};

typedef struct HashTable HashTable;
// Define the hash table here
struct HashTable
{
	Ht_item	**items;
	LinkedList	**overflow_buckets;
	int		size;
	int		count;
};
//we will also keep track of the number of elements in the Hash table using count, and store the size of the table in size.



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

/**
 * @brief
 *
 * @param prompt
 * @param bool_quotes
 */
void	ft_expand(t_prompt *prompt, int bool_quotes);

# endif

