/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:33:06 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/25 15:35:36 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/ft_hash_table.h"
# include "../../ft_printf/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// comando para compilar o programa
// gcc main.c ../../sources/hash_table/*.c ../../ft_printf/libft/*.c -I ../../includes/ && ./a.out

void	display(t_hash *array)
{
	int		i;
	t_hnode	*temp;

	i = -1;
	while(++i < TABLE_SIZE)
	{
		temp = array[i].head;
		if (temp == NULL)
			printf("array[%d] -->NULL\n", i);
		else
		{
			printf("array[%d] --> ", i);
			while (temp != NULL)
			{
				printf("%s --> ", temp->key);
				temp = temp->next;
			}
			printf("NULL\n");
		}
	}
}

int	size_of_array(t_hash *array)
{
	return (array[0].size);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		c;
	int		n;
	int		choice;
	char	key[MAX_STRING];
	char	value[MAX_STRING];
	t_hash	*array;
	char	*tmp;

	c = 1;
	system("clear");
	// array = (t_hash *)malloc(TABLE_SIZE * sizeof(t_hash));
	// ft_init_array(array);
	while(c == 1)
	{
		printf("Implementation of Hash Table in C chaining with Singly Linked List \n\n");
		printf("MENU-: \n1.Inserting item in the Hash Table"
							"\n2.Removing item from the Hash Table"
							"\n3.Check the size of Hash Table"
							"\n4.To display a Hash Table"
							"\n5.Retrieva value"
							"\n6.Delete the hash table"
			"\n\n Please enter your choice -: ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("Inserting element in Hash Table\n");
			array = ft_create_table(envp);
			// ft_split_env(array, envp);
		}
		else if (choice == 2)
		{
			printf("Deleting in Hash Table \nEnter the key to delete-:");
			scanf("%s", key);
			ft_remove_element(array, key);
		}
		else if (choice == 3)
		{
			n = size_of_array(array);
			printf("Size of Hash Table is-:%d\n", n);
		}
		else if (choice == 4)
			display(array);
		else if (choice == 5)
		{
			printf("Enter key-:\t");
			scanf("%s", key);
			tmp = ft_find_value(array, key);
			printf("%s", tmp);
			//free(tmp);
		}
		else if (choice == 6)
		{
			printf("Delete table\n");
			ft_destroy_hash(array);
		}
		else
			printf("Wrong Input\n");
		printf("\nDo you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
	}
	getchar();
	return (0);
}
