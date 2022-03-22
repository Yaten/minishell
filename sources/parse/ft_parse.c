/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:20:25 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/18 01:38:19 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

// t_cmd	*ft_parse_cmd(char *cmd)
// {
// 	t_cmd	*new_cmd;

// 	new_cmd = (t_cmd *)ft_calloc(1, sizeof(t_cmd));
// 	new_cmd->args = ft_split(cmd, ' ');
// 	return (new_cmd);
// }

// void	*ft_node_create(t_cmd *new_cmd)
// {
// 	t_prompt	prompt;
// 	t_cmd		*first;

// 	first = prompt.cmd;
// 	while (first->next != NULL)
// 		first = first->next;
// 	new_cmd->prev = first;
// 	first->next = new_cmd;
// }

// void	create_cmd(char *cmd, char *relation)
// {
// 	t_cmd	*first;
// 	t_cmd	*new_cmd;

// 	new_cmd = parse_cmd(cmd);
// 	new_cmd->input = NULL;
// 	new_cmd->output = NULL;
// 	new_cmd->relation = relation;
// 	new_cmd->builtin = 0;
// 	new_cmd->next = NULL;
// 	new_cmd->prev = NULL;
// 	if (first == NULL)
// 		prompt.cmd = new_cmd;
// 	else
// 		ft_note_create(new_cmd);
// }

// int		ft_builtin_check(t_cmd *cmd)
// {
// 	//if(!(ft_strcmp(cmd->args[0], "cmd", 3)))
// 	if(!cmd->args[0])
// 		return (cmd->builtin = FALSE);
// 	if(!(ft_strcmp(cmd->args[0], "echo", 4)))
// 		return (cmd->builtin = TRUE);
// 	if(!(ft_strcmp(cmd->args[0], "cd", 2)))
// 		return (cmd->builtin = TRUE);
// 	if(!(ft_strcmp(cmd->args[0], "pwd", 3)))
// 		return (cmd->builtin = TRUE);
// 	if(!(ft_strcmp(cmd->args[0], "export", 6)))
// 		return (cmd->builtin = TRUE);
// 	if(!(ft_strcmp(cmd->args[0], "unset", 5)))
// 		return (cmd->builtin = TRUE);
// 	if(!(ft_strcmp(cmd->args[0], "env", 3)))
// 		return (cmd->builtin = TRUE);
// 	if(!(ft_strcmp(cmd->args[0], "exit", 4)))
// 		return (cmd->builtin = TRUE);
// 	return (cmd->builtin = FALSE);
// }

void	ft_parse(t_prompt *prompt)
{
	char	**split;
	int		i;

	//splita pelo space
	split = ft_split(prompt->input_string, ' ');
	i = 0;

	//mandar pra struct e
	//fazer todos os checks

	//ft_check();
	// if (ft_check == 1)
	// {
	// 	printf("check 1\n");
	// }
	// if (ft_check >= 2)
	// {
	// 	printf("check 2\n");
	// }

	printf("%s------------------------%s\n", GREEN, RESET);
	printf("input >> %s%s\n", WHITE, prompt->input_string);
	printf("%s------------------------%s\n", GREEN, RESET);
	while (split[i])
	{
		printf("%ssplited >> %s%s\n", CYAN, WHITE, split[i]);
		printf("%sloop %d\n", RESET, i+1);
		printf("%s------------------------%s\n", GREEN, RESET);
		i++;
	}
}
