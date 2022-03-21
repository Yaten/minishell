# include <stdio.h>
# include <stdlib.h>

typedef struct	s_node
{
	int	key;
	int	value;
	struct	s_node	*next;
}t_node;

typedef struct	s_arrayitem
{
	t_node	*head;
	t_node	*tail;
}t_arrayitem;

t_arrayitem	*array;
int	size = 0;
int	max = 10;

void	insert(int key, int value);

void	init_array()
{
	int	i;

	i = -1;
	while (++i < max)
	{
		array[i].head = NULL;
		array[i].tail = NULL;
	}
}

void	rehash()
{
	int			i;
	int			n;
	t_arrayitem	*tmp;

	i = -1;
	n = max;
	size = 0;
	max *= 2;
	tmp = array;
	array = (t_arrayitem *)malloc(max * sizeof(t_arrayitem));
	init_array();
	while (++i < n)
	{
		t_node	*list = (t_node *)tmp[i].head;
		if (list == NULL)
			continue ;
		else
		{
			while (list != NULL)
			{
				insert(list->key, list->value);
				list = list->next;
			}
		}
	}
	tmp = NULL;
}

t_node	*get_element(t_node *list, int find_index)
{
	int		i;
	t_node	*tmp;

	i = -1;
	while (++i < find_index)
		tmp = tmp->next;
	return (tmp);
}

int	find(t_node *list, int key)
{
	t_node	*tmp;
	int		retval;

	tmp = list;
	retval = 0;
	while (tmp != NULL)
	{
		if (tmp->key == key)
			return (retval);
		tmp = tmp->next;
		retval++;
	}
	return (-1);
}

int	hashcode(int key)
{
	return (key % max);
}

void	insert(int key, int value)
{
	float	n;
	int		index;
	t_node	*list;
	t_node	*item;

	n = 0.0;
	index = hashcode(key);
	list = (t_node *)array[index].head;
	item = (t_node *)malloc(sizeof(t_node));
	item->key = key;
	item->value = value;
	item->next = NULL;
	if (list == NULL)
	{
		printf("Inserting %d(key) and %d(value)\n", key, value);
		array[index].head = item;
		array[index].tail = item;
		size++;
	}
	else
	{
		int	find_index = find(list, key);
		if (find_index == -1)
		{
			array[index].tail->next = item;
			array[index].tail = item;
			size++;
		}
		else
		{
			t_node	*element = get_element(list, find_index);
			element->value = value;
		}
	}
	n = (1.0 * size) / max;
	if (n >= 0.75)
	{
		printf("going to rehash\n");
		rehash();
	}
}

int	main(void)
{
	int	choice;
	int	key;
	int	value;
	int	n;
	int	c;

	array = (t_arrayitem *)malloc(max * sizeof(t_arrayitem));
	init_array();
	c = 1;
	while (c)
	{
		printf("Implmentation of Hash Table in C chaining with singly Linked List\n\n");
		printf("MENU-: \n1.Inserting item in the Hash Table"
						"\n2.Removing item from the Hash Table"
						"\n3.Check the size of Hash Table"
						"\n4.To display a Hash Table"
					"\n\n Please enter your chioce -:");
		scanf("%d", &choice);
		if (choice == 1)
		{
			printf("Inserting element in Hash Table\n");
			printf("Enter key and value -:\t");
			scanf("%d %d", &key, &value);
			insert(key, value);
		}
	}
	return (0);
}













