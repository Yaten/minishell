/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:21:32 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/18 17:26:02 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

# define MAXINPUT 1024

// typedef struct s_node
// {
// 	char			**args;
// 	char			*operators;
// 	int				fd_in;
// 	int				fd_out;
// 	struct s_node	*next;
// }t_node;

typedef struct	s_prompt
{
	char	*user;
	char	*hostname;
	char	*path;
	char	*result;
	char	*cmd;
	char	input_string[MAXINPUT];
}t_prompt;

void	ft_parse(char *line, char **envp);

int		ft_find_path(char *aux);

int		ft_create_cmd(char *line);

void	ft_destroy_list();

void	ft_expand(char *input_string, int bool_quotes);

void	ft_quoting(t_prompt *prompt, char *input_string, int bool_quotes);

int		ft_create_pipe(char *line);

int		ft_create_redir_output(char *line);

void	ft_create_redir_input(char *line);

void	ft_create_append(char *line);

int		ft_tokenize(t_prompt *prompt);

#endif
