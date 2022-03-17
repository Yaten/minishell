// aula 260: Tabela hash linear com vetor
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

void	inicializarTabela(int t[])
{
	int	i;

	while (++i < TAM)
		t[i] = 0;
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














