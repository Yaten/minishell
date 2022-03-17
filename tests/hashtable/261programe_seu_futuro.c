// aula 261: Tabela hash linear com vetor
# include <stdio.h>
# include <stdlib.h>

//-> Uma maneira de determina o tamanho da nossa tabela:
// fazer duas vezes a quantidade de elementos e ai pegamos o número primo
// mais próximo
//
// -> Exemplo:
// 2 * 15 = 30
// O primo mais próximo de 30 é o 31
# define TAM 31

//########################### INÍCIO LINKED ###########################//

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
	printf("Size: %d ", l->size);
	while (tmp != NULL)
	{
		printf("%d -> ", tmp->val);
		tmp = tmp->next;
	}
	puts("");
}

void	ft_list_destroy(t_slist **l_ref)
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

int	buscar_na_lista(t_slist *l, int val)
{
	t_snode	*aux;

	aux = l->begin;
	while (aux && aux->val != val)
		aux = aux->next;
	if (aux)
		return (aux->val);
	return (0);
}

//########################### FIM LINKED ###########################//

void	inicializarTabela(t_slist t[])
{
	int	i;

	t[i] = 'i';
	while (++i < TAM)
		t[i] = ft_slinkedlist_create();

}

int	funcaoHash(int chave)
{
	return (chave % TAM);
}

void	inserir(int t[], int valor)
{
	int	id;

	id = funcaoHash(valor);
	while (t[id] != 0)
		id = funcaoHash(id + 1);
	t[id] = valor;
}

int	busca(int t[], int chave)
{
	int	id;

	id = funcaoHash(chave);
	printf("\n\tIndice gerado: %d\n", id);
	while (t[id] != 0)
	{
		if (t[id] == chave)
			return (t[id]);
		else
			id = funcaoHash(id + 1);
	}
	return (0);
}

void	imprimir(int t[])
{
	int	i;

	i = -1;
	while (++i < TAM)
		printf("\t%d = %d\n", i, t[i]);
}

int	main(void)
{
	int	i;
	int	opcao;
	int	retorno;
	int	valor;
	int	tabela[TAM];

	i = 1;
	inicializarTabela(tabela);
	system("clear");
	while (i)
	{
		printf("\n\t0 - Sair\n\t1 - Inseri\n\t2 - Buscar\n\t3 - Imprimir\n");
		scanf("%d", &opcao);
		if (opcao == 0)
		{
			puts("Encerrando o programa!");
			i = 0;
		}
		else if (opcao == 1)
		{
			printf("\tQual valor deseja inserir? ");
			scanf("%d", &valor);
			inserir(tabela, valor);
		}
		else if (opcao == 2)
		{
			printf("\tQual valor deseja buscar? ");
			scanf("%d", &valor);
			retorno = busca(tabela, valor);
			if (retorno != 0)
				printf("\tValor encontrando: %d\n", retorno);
			else
				printf("\tValor não encontrando!\n");
		}
		else if (opcao == 3)
		{
			imprimir(tabela);
		}
		else
			puts("Opção inválida!");
	}
	return (0);
}














