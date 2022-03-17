# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}t_snode;

typedef struct s_list
{
	int		size;
	t_snode	*begin;
	t_snode	*end;
}t_slist;

int	ft_slist_is_empty(t_slist *l)
{
	return (l->size == 0);
}

t_slist	*ft_slinkedlist_create()
{
	t_slist	*l;

	l = (t_slist *)calloc(1, sizeof(t_slist));
	l->begin = NULL;
	l->end = NULL;
	l->size = 0;
	return (l);
}

t_snode	*ft_snode_create(int value)
{
	t_snode	*new;

	new = (t_snode *)calloc(1, sizeof(t_snode));
	new->next = NULL;
	new->val = value;
	return (new);
}

void	ft_slist_add_last(t_slist *l, int val)
{
	t_snode	*new;

	new = ft_snode_create(val);
	if (ft_slist_is_empty(l))
		l->begin = new;
	else
		l->end->next = new;
	l->end = new;
	l->size++;
}

void	ft_slist_print(const t_slist *l)
{
	t_snode	*tmp;

	tmp = l->begin;
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->val);
		tmp = tmp->next;
	}
	puts("");
}

void	ft_slist_destroy(t_slist **l_ref)
{
	t_slist	*l;
	t_snode	*p;
	t_snode	*aux;

	l = *l_ref;
	p = l->begin;
	while (p != NULL)
	{
		aux = p;
		p = p->next;
		free(aux);
	}
	free(l);
	*l_ref = NULL;
}

int	main(void)
{
	t_slist	*l;

	l = ft_slinkedlist_create();
	ft_slist_add_last(l, 10);
	ft_slist_add_last(l, 2);
	ft_slist_add_last(l, 4);
	ft_slist_add_last(l, 5);
	ft_slist_add_last(l, 7);
	ft_slist_print(l);
	ft_list_destroy(&l);
	return (0);
}
