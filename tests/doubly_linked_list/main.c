/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 09:51:04 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/21 12:40:10 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/ft_minishell.h"
# include "../../ft_printf/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// comando para compilar o programa
// gcc alpha_test.c ../../sources/hash_table/*.c ../../ft_printf/libft/*.c -I ../../includes/ && ./a.out

void	ft_dlist_print(const t_doubly *l)
{
	t_node	*p;

	p = l->begin;
	printf("l -> ");
	while (p != NULL)
	{
		printf("%s -> ", p->val);
		p = p->next;
	}
	printf("NULL\n");
	if (l->end == NULL)
		printf("l->end = NULL\n");
	else
		printf("l->end = %s\n", l->end->val);
	printf("Size: %lu\n", l->size);
	puts("");
}

int	main(void)
{
	int			c;
	int			choice;
	char		value[1024];
	t_doubly	*l;

	c = 1;
	l = ft_list_create();
	system("clear");
	while(c == 1)
	{
		printf("Implementation of Doubly linked list\n\n");
		printf("MENU-: \n1.Insert a value at the beginning of the list"
							"\n2.Insert a value at the end of the list"
							"\n3.Display the list"
							"\n4.Destroy the list"
			"\n\n Please enter your choice -: ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("Inserting element in list\n");
			scanf("%s", value);
			ft_list_add_first(l, value);
		}
		else if (choice == 2)
		{
			printf("Inserting element in list\n");
			scanf("%s", value);
			ft_list_add_last(l, value);
		}
		else if (choice == 3)
		{
			puts("print list");
			ft_list_print(l);
		}
		else if (choice == 3)
		{
			puts("destroy list");
			ft_list_destroy(&l);
			break ;
		}
		else
			printf("Wrong Input\n");
		printf("\nDo you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
	}
	getchar();
	return (0);
}















