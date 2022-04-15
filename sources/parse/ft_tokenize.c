/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:11:53 by prafael-          #+#    #+#             */
/*   Updated: 2022/04/14 22:04:13 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

// void	ft_syntax(t_doubly *token)
// {
// 	t_node	*tmp;

// 	tmp = token->begin;
// 	while (tmp)
// 	{
// 		if (!ft_strncmp(tmp->operators, "pipe", 4))
// 		{
// 			if (ft_strncmp(tmp->prev->operators, "word", 4) ||
// 			ft_strncmp(tmp->next->operators, "word", 4))
// 			{
// 				ft_putstr_fd("Syntax er")
// 			}
// 		}
// 	}
// }

void	ft_define_token(t_doubly *token)
{
	t_node	*tmp;

	tmp = token->begin;
	while (tmp)
	{
		if (!ft_strncmp(tmp->val[0], "|", 1))
			tmp->operators = "pipe";
		else if (!ft_strncmp(tmp->val[0], "<", 1))
			tmp->operators = "redir_input";
		else if (!ft_strncmp(tmp->val[0], "<<", 2))
			tmp->operators = "here_doc";
		else if (!ft_strncmp(tmp->val[0], ">", 1))
			tmp->operators = "redir_output";
		else if (!ft_strncmp(tmp->val[0], ">>", 2))
			tmp->operators = "redir_append";
		else
			tmp->operators = "word";
		tmp = tmp->next;
	}
	ft_list_print2(token);
}

int	ft_is_space(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || \
	c == '\v' || c == '\f');
}

void	ft_tokenize(t_prompt *prompt)
{
	char		*begin;
	char		*end;
	t_doubly	*token;

	token = ft_list_create();
	begin = prompt->input_string;
	while (*begin)
	{
		while (ft_is_space(*begin))
			begin++;
		end = begin;
		while (!ft_strchr(" ><|", *end))
		{
			if (ft_strchr(" ><|", *end + 1))
				break ;
			end++;
		}
		if (ft_strchr("><|", *begin))
		{
			if (*begin == *(begin + 1))
				end = end + 2;
			else
				end++;
		}
		ft_list_add_last(token, ft_substr(prompt->input_string, \
		begin - prompt->input_string, end - begin + 1));
		begin = end;
	}
	ft_define_token(token);
	// ft_list_print(token);
}
