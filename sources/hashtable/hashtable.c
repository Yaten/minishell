/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 13:11:58 by prafael-          #+#    #+#             */
/*   Updated: 2022/03/16 20:52:53 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/ft_minishell.h"
# include <stdlib.h>
# include <string.h>
#define CAPACITY 50000

//check collide // asciivalue

unsigned long hash_function(char *str)
{
	unsigned long i = 0;
	for (int j=0; str[j]; j++)
		i += str[j];
	return i % CAPACITY;
}

static LinkedList	*allocate_list()
{
	// Allocate memory for a Linkedlist pointer
	LinkedList	*list;
	list = (LinkedList *)malloc(sizeof(LinkedList));
	return (list);
}

static LinkedList	*linkedlist_insert(LinkedList *list, Ht_item *item)
{
	// Inserts the item onto the Linked List
	if (!list)
	{
		LinkedList	*head;

		head = allocate_list();
		head->item = item;
		head->next = NULL;
		list = head;
		return (list);
	}
	else if (list->next == NULL)
	{
		LinkedList	*node;

		node = allocate_list();
		node->item = item;
		node->next = NULL;
		list->next = node;
		return (list);
	}
	LinkedList	*tmp;

	tmp = list;
	while (tmp->next->next)
		tmp = tmp->next;
	LinkedList	*node;
	node = allocate_list();
	node->item = item;
	node->next = NULL;
	node->next = node;
}

static Ht_item	*linkedlist_remove(LinkedList *list)
{
	// Removes the head from the linked list
	// and returns the item of the popped element
	if (!list)
		return (NULL);
	if (!list->next)
		return (NULL);
	LinkedList	*node;
	LinkedList	*tmp;

	node = list->next;
	tmp = list;
	tmp->next = NULL;
	list = node;
	Ht_item	*it;

	it = NULL;
	memcpy(tmp->item, it, sizeof(Ht_item));
	free(tmp->item->key);
	free(tmp->item->value);
	free(tmp->item);
	free(tmp);
	return (it);
}

static void	free_linke;

Ht_item *create_item(char *key, char *value)
{
	Ht_item *item = (Ht_item *)malloc(sizeof(Ht_item));
	item->key = (char *)malloc(strlen(key) + 1);
	item->value = (char *)malloc(strlen(value) + 1);

	strcpy(item->key, key);
	strcpy(item->value, value);

	return item;
}

HashTable *create_table(int size)
{
	HashTable *table = (HashTable *)malloc(sizeof(HashTable));
	table->size = size;
	table->count = 0;
	table->items = (Ht_item **) calloc(table->size, sizeof(Ht_item *));
	for (int i = 0; i < table->size; i++)
		table->items[i] = NULL;
	return table;
}

void free_item(Ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void free_table(HashTable* table)
{
	for (int i = 0; i < table->size; i++)
	{
		Ht_item* item = table->items[i];
		if (item != NULL)
			free_item(item);
	}
	free(table->items);
	free(table);
}

void handle_collision(HashTable *table, unsigned long index, Ht_item *item)
{
	LinkedList *head = table->overflow_buckets[index];

	if (head == NULL)
	{
		//precisa criar a lista
		head = allocate_list();
		head->item = item;
		table->overflow_buckets[index] = head;
		return;
	}
	else
	{
		//insere na lista
		table->overflow_buckets[index] = linkedlist_isert(head, item);
		return;
	}
}

void ht_insert(HashTable* table, char *key, char *value)
{
	//cria o item
	Ht_item *item = create_item(key, value);
	//computa o index
	unsigned long index = hash_function(key);

	Ht_item *current_item = table->items[index];

	if (current_item == NULL)
	{
	//key n existe
		if (table->count == table->size)
		{
			//ht full
			printf("Insert Error: Hash Table is full.\n");
			//remove o item criado
			free_item(item);
			return;
		}
		//insere direto
		table->items[index] = item;
		table->count++;
	}
	else
	{
		//caso 1: so precisa dar update no value
		if(strcmp(current_item->key, key) == 0)
		{
			strcpy(table->items[index]->value, value);
			return;
		}
		else
		{
			//caso 2:colide, precisamos cuidar do caso depois
			handle_collision(table, index, item);
			return;
		}
	}
}

char *ht_search(HashTable *table, char *key)
{
	//procura pela key na HT e retorna null se n existe
	int index = hash_function(key);
	Ht_item *item = table->items[index];

	//garantia que n vai mover null
	if (item != NULL)
	{
		if (strcmp(item->key, key) == 0)
			return item->value;
	}
	return NULL;
}

void	print_search(HashTable *table, char *key)
{
	char	*val;

	if ((val = ht_search(table, key)) == NULL)
	{
		printf("%s does not exist\n", key);
		return ;
	}
	else
		printf("Key:%s, Value:%s\n", key, val);
}

void	print_table(HashTable *table)
{
	print("\n------------------------------\n");
	for (int i = 0; i < table->size; i++)
	{
		if (table->items[i])
		{
			printf("Index:%d, Key:%s, Value:%s", i, table->items[i]->key, table->items[i]->value);
			if (table->overflow_buckets[i])
			{
				printf(" => Overflow Bucket => ");
				LinkedList	*head = table->overflow_buckets[i];
				while (head)
				{
					printf("Key:%s, Value:%s ", head->item->key, head->item->value);
					head = head->next;
				}
			}
			printf("\n");
		}
	}
	print("------------------------------\n");
}

int	main()
{
	HashTable	*ht;

	ht = create_table(CAPACITY);
	ht_insert(ht, "1", "First address");
	ht_insert(ht, "2", "Second address");
	ht_insert(ht, "Hel", "Third address");
	ht_insert(ht, "Cau", "Fourth address");
	print_search(ht, "1");
	print_search(ht, "2");
	print_search(ht, "3");
	print_search(ht, "Hel");
	print_search(ht, "Cau"); // Collision !
	print_table(ht);
	ht_delete(ht, "1");
	ht_delete(ht, "Cau");
	print_table(ht);
	free_table(ht);
	return (0);
}



















