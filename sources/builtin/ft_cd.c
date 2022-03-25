/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:50:11 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/24 21:21:24 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

void	ft_cd()
{
	// char	*tmp;
	char	cwd[256];
	// int		i;

	//g_data
	// if (g_data.node->args[2] != NULL)
	// {
	// 	printf("deu ruim mane");
	// 	return ;
	// }
	// tmp = g_data.node->args[1];
	// if (getcwd(cwd, sizeof(cwd)) == NULL)
	// 	perror("getcwd() error");
	// else
	// 	printf("%s\n", cwd);
	getcwd(cwd, 100);
	// printf("%s\n", getcwd(cwd, 100));
	if (chdir("/home") != 0)
		perror("chdir() to /usr failed");
	printf("%s\n", getcwd(cwd, 100));
	// return (0);
}
