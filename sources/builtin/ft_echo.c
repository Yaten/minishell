/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 15:49:30 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/23 20:51:33 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_minishell.h"

// static int	ft_compare_operators(char *tmp)
// {
// 	// int	i;
// 	int	j;

// 	// i = -1;
// 	// while (tmp[++i])
// 	// {
// 	// 	j = -1;
// 	// 	while (g_data.operators[++j])
// 	// 	{
// 	// 		if (!ft_strncmp(tmp, g_data.operators[j], ft_strlen(tmp[i])))
// 	// 			return (0);
// 	// 	}
// 	// }
// 	j = -1;
// 	while (g_data.operators[++j])
// 	{
// 		if (!ft_strncmp(tmp, g_data.operators[j], ft_strlen(tmp)))
// 			return (0);
// 	}
// 	return (1);
// }

void	ft_echo()
{
	int		i;
	int		boll_n;
	char	**tmp;
	// int		test;

	i = 1;
	boll_n = 0;
	tmp = g_data.node->args;
	if (!ft_strncmp(tmp[i], "-n", 2)) // echo yaten lindo\0 >\n
	{
		boll_n = 1;
		++i;
	}
	// while (tmp[i] && ft_compare_operators(tmp[i]))
	while (tmp[i])
	{
		//printf("\ntmp[i]: %s", tmp[i]);
		// if (!ft_compare_operators(tmp[i]))
		// {
		// 	if (!boll_n)
		// 	{
		// 		tmp[i - 1][ft_strlen(tmp[i])] = '\n';
		// 		boll_n = 0;
		// 	}
		// 	else
		// 		tmp[i - 1][ft_strlen(tmp[i])] = '\n';
		// 	break ;
		// }
		ft_putstr_fd(tmp[i], 1);
		ft_putstr_fd(" ", 1);
		i++;
 		// printf("boll_n: %d\n", boll_n);
	}
	// printf ("fora do loop: %c\n", tmp[i - 1][0]);
	// test = ft_strlen(tmp[i - 1]);
	// printf("len: %d\n", test);
	// puts("");
	// ft_putchar_fd(tmp[i - 1][0], 1);
	if (!boll_n)
	{
		puts("");
		tmp[i - 1][ft_strlen(tmp[i - 1]) + 1] = '\n';
	}
}
