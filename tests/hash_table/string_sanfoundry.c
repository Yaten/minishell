# include "../../ft_printf/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define TABLE_SIZE 1031
# define MAX_STRING 1024

typedef struct	s_node
{
	char			*key;
	char			*value;
	struct s_node	*next;
}t_node;

typedef struct	s_hash
{
	t_node	*head;
	t_node	*tail;
	int		size;
}t_hash;

int	hashcode(char *key)
{
	char			*ptr;
	int				tmp;
	unsigned int	val;

	val = 0;
	ptr = key;
	while (*ptr != '\0')
	{
		val = (val << 4) + (*ptr);
		tmp = (val & 0xf0000000);
		if (tmp)
		{
			val = val ^ (tmp >> 24);
			val = val ^ tmp;
		}
		ptr++;
	}
	return (val % TABLE_SIZE);
}

t_node*	get_element(t_node *list, int find_index);
void	remove_element(t_hash *array, char *key);
void	rehash(t_hash *array);
void	init_array(t_hash *array);
int		find(t_node *list, char *key);

void	insert(t_hash *array, char *key, char *value)
{
	float	n;
	int		index;
	int		find_index;
	t_node	*list;
	t_node	*item;

	n = 0.0;
	index = hashcode(key);
	list = (t_node *)array[index].head;
	item = (t_node *)malloc(sizeof(t_node));
	item->key = strdup(key);
	item->value = strdup(value);
	item->next = NULL;
	if (list == NULL)
	{
		printf("Inserting %s(key) and %s(value) \n", key, value);
		array[index].head = item;
		array[index].tail = item;
		array[index].size++;
	}
	else
	{
		find_index = find(list, key);
		if (find_index == -1)
		{
			array[index].tail->next = item;
			array[index].tail = item;
			array[index].size++;
		}
		else
		{
			while (list->next)
				list = list->next;
			list->next = item;
			array[index].tail = item;
		}
	}
	// n = (1.0 * array[index].size) / TABLE_SIZE;
	// if (n >= 0.75)
	// {
	// 	printf("going to rehash\n");
	// 	rehash(array);
	// }
}

// void	rehash(t_hash *array)
// {
// 	int		i;
// 	int		n;
// 	int		max;
// 	t_hash	*temp;
// 	t_node	*list;
// 	max = TABLE_SIZE;
// 	n = TABLE_SIZE;
// 	temp = array;
// 	array[0].size = 0;
// 	max *= 2;
// 	array = (t_hash *)malloc(TABLE_SIZE * sizeof(t_hash));
// 	init_array(array);
// 	i = -1;
// 	while(++i < n)
// 	{
// 		list = (t_node*) temp[i].head;
// 		if (list == NULL)
// 			continue ;
// 		else
// 		{
// 			while (list != NULL)
// 			{
// 				insert(array, list->key, list->value);
// 				list = list->next;
// 			}
// 		}
// 	}
// 	temp = NULL;
// }

int	find_value(t_hash *array, char *key)
{
	t_hash	*temp;
	int		i;

	i = -1;
	temp = array;
	while (++i < TABLE_SIZE)
	{
		while (temp[i].head)
		{
			if (!strcmp(temp[i].head->key, key))
			{
				printf("%s\n", temp[i].head->value);
				return (1);
			}
			temp[i].head = temp[i].head->next;
		}
	}
	return (0);
}

int	find(t_node *list, char *key)
{
	int		retval;
	t_node	*temp;

	retval = 0;
	temp = list;
	while (temp != NULL)
	{
		if (!strcmp(temp->key, key))
			return (retval);
		temp = temp->next;
		retval++;
	}
	return (-1);
}

t_node	*get_element(t_node *list, int find_index)
{
	int		i;
	t_node	*temp;

	i = -1;
	temp = list;
	while (++i != find_index)
		temp = temp->next;
	return temp;
}

void	remove_element(t_hash *array, char *key)
{
	t_node	*list;
	t_node	*temp;
	int		index;
	int		find_index;

	index = hashcode(key);
	list = (t_node*) array[index].head;
	if (list == NULL)
		printf("This key does not exists\n");
	else
	{
		find_index = find(list, key);
		if (find_index == -1)
			printf("This key does not exists\n");
		else
		{
			temp = list;
			if (!strcmp(temp->key, key))
			{
				array[index].head = temp->next;
				printf("This key has been removed\n");
				return;
			}
			while (strcmp(temp->next->key, key))
				temp = temp->next;
			if (array[index].tail == temp->next)
			{
				temp->next = NULL;
				array[index].tail = temp;
			}
			else
				temp->next = temp->next->next;
			printf("This key has been removed\n");
		}
	}
}

void	display(t_hash *array)
{
	int		i;
	t_node	*temp;

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

void	init_array(t_hash *array)
{
	int i;
	i = -1;
	while(++i < TABLE_SIZE)
	{
		array[i].head = NULL;
		array[i].tail = NULL;
	}
}

int	size_of_array(t_hash *array)
{
	return (array[0].size);
}

int	split_env(t_hash *array, char *envp[])
{
	int		j;
	char	*last;
	char	*tmp1;
	char	*before;

	j = -1;
	while (envp[++j])
	{
		tmp1 = ft_strchr(envp[j], '=');
		before = ft_substr(envp[j], 0, tmp1 - envp[j]);
		last = ft_substr(envp[j], tmp1 + 1 - envp[j], ft_strlen(envp[j]));
		// printf("Antes: %s\n", before);
		// printf("Depois: %s\n", last);
		insert(array, before, last);
		free (before);
		free (last);
	}
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		c;
	int		n;
	int		choice;
	char	key[MAX_STRING];
	char	value[MAX_STRING];
	t_hash	*array;

	c = 1;
	system("clear");
	array = (t_hash *)malloc(TABLE_SIZE * sizeof(t_hash));
	init_array(array);
	while(c == 1)
	{
		printf("Implementation of Hash Table in C chaining with Singly Linked List \n\n");
		printf("MENU-: \n1.Inserting item in the Hash Table"
							"\n2.Removing item from the Hash Table"
							"\n3.Check the size of Hash Table"
							"\n4.To display a Hash Table"
							"\n5.Retrieva value"
			"\n\n Please enter your choice -: ");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("Inserting element in Hash Table\n");
			// printf("Enter key and value-:\t");
			// scanf("%s %s", key, value);
			// insert(array, key, value);
			split_env(array, envp);
		}
		else if (choice == 2)
		{
			printf("Deleting in Hash Table \nEnter the key to delete-:");
			scanf("%s", key);
			remove_element(array, key);
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
			find_value(array, key);
			// if (find_value(array, key))
			// 	printf("estraiu o valor\n");
		}
		else
			printf("Wrong Input\n");
		printf("\nDo you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
	}
	getchar();
	return (0);
}
