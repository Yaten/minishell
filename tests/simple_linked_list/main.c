#include <stdio.h>
# include "../../includes/ft_minishell.h"
# include "../../ft_printf/libft/libft.h"

int main (void)
{
	t_slist *l;

	l = ft_slinkedlist_create();

	ft_slist_add_last(l, "1");
	ft_slist_add_last(l, "2");
	ft_slist_add_last(l, "3");
	ft_slist_add_last(l, "4");
	ft_slist_print(l);
	ft_slist_destroy(&l);

	l = ft_slinkedlist_create();

	ft_slist_add_last(l, "666");
	ft_slist_print(l);
	ft_slist_destroy(&l);
}


// gcc main.c ../../sources/simple_linked_list/*.c ../../ft_printf/libft/*.c -I ../../includes/ && ./a.out