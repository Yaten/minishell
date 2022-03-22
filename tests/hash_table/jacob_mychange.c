# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAXNAME 256
# define TABLE_SIZE 10
// # define DELETED_NODE (t_person *)(0xFFFFFFFFFFFFFFFFUL)

typedef struct s_person
{
	char	name[MAXNAME];
	int		age;
	struct s_person	*next;
	// ... add other stuff later, maybe.
}t_person;

// t_person *hash_table[TABLE_SIZE];

unsigned int	hash(char *name)
{
	int				i;
	int				length;
	unsigned int	hash_value;

	i = -1;
	hash_value = 0;
	length = strnlen(name, MAXNAME);
	while (++i < length)
	{
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}
	return (hash_value);
}

void	print_table(t_person *hash_table[])
{
	int	i;

	i = -1;
	puts("\tStart");
	while (++i < TABLE_SIZE)
	{
		if (hash_table[i] == NULL)
			printf("\t%d\t---\n", i);
		else
		{
			printf("\t%d\t", i);
			t_person	*tmp = hash_table[i];
			while (tmp != NULL)
			{
				printf("%s - ", tmp->name);
				tmp = tmp->next;
			}
			printf("\n");
		}
	}
	puts("\tEnd");
}

t_person	*hash_table_delete(char *name, t_person *hash_table[])
{
	int			i;
	int			index;
	t_person	*tmp;
	t_person	*prev;

	i = -1;
	prev = NULL;
	index = hash(name);
	tmp = hash_table[index];
	while (tmp != NULL && strncmp(tmp->name, name, MAXNAME) != 0)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	if (prev == NULL)
		hash_table[index] = tmp->next; // deleting the head
	else
		prev->next = tmp->next;
	return (tmp);
}

// Find a person in the table by their name
t_person	*hash_table_lookup(char *name, t_person *hash_table[])
{
	int			i;
	int			index;
	t_person	*tmp;

	i = -1;
	index = hash(name);
	tmp = hash_table[index];
	while (tmp != NULL && strncmp(tmp->name, name, MAXNAME) != 0)
		tmp = tmp->next;
	return (tmp);
}

int	hash_table_insert(t_person *p, t_person *hash_table[])
{
	int	i;

	i = -1;
	if (p == NULL)
		return (0);
	int	index = hash(p->name);
	p->next = hash_table[index];
	hash_table[index] = p;
	return (1);
}

void	init_hash_table(t_person *hash_table[])
{
	int	i;

	i = -1;
	while (++i < TABLE_SIZE)
		hash_table[i] = NULL;
	// table is empty
}

int	main(void)
{
	t_person	hash_table[TABLE_SIZE];

	init_hash_table(hash_table);
	print_table(hash_table);

	t_person	willian = {.name = "willian", .age = 23};
	t_person	kate = {.name = "kate", .age = 34};
	t_person	Mpho = {.name = "Mpho", .age = 30};
	t_person	Sarah = {.name = "Sarah", .age = 54};
	t_person	Edna = {.name = "Edna", .age = 15};
	t_person	Maren = {.name = "Maren", .age = 25};
	t_person	eliza = {.name = "eliza", .age = 34};
	t_person	robert = {.name = "robert", .age = 1};
	t_person	jane = {.name = "jane", .age = 75};

	hash_table_insert(&willian, hash_table);
	hash_table_insert(&kate, hash_table);
	hash_table_insert(&Mpho, hash_table);
	hash_table_insert(&Sarah, hash_table);
	hash_table_insert(&Edna, hash_table);
	hash_table_insert(&Maren, hash_table);
	hash_table_insert(&eliza, hash_table);
	hash_table_insert(&robert, hash_table);
	hash_table_insert(&jane, hash_table);
	print_table(hash_table);

	t_person	*tmp;
	tmp = hash_table_lookup("Mpho", hash_table);
	if (tmp == NULL)
		printf("Not found!\n");
	else
		printf("Found %s.\n", tmp->name);

	tmp = hash_table_lookup("George", hash_table);
	if (tmp == NULL)
		printf("Not found!\n");
	else
		printf("Found %s.\n", tmp->name);

	hash_table_delete("Mpho", hash_table);
	if (tmp == NULL)
		printf("Not found!\n");
	else
		printf("Found %s.\n", tmp->name);

	print_table(hash_table);
	return (0);
}













