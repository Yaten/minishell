/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsiqueir <rsiqueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 09:25:08 by wrosendo          #+#    #+#             */
/*   Updated: 2022/03/09 20:11:03 by rsiqueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_minishell.h"
# include <stdio.h>

/* Concatena duas string e da free na primeira(s1) */
char	*concat_and_clean(char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	free(s1);
	return (str);
}

/* Retorna o path retirando /home/nome_do_user */
char *find_path(char *abs_path)
{
	char *pointer;

	pointer = abs_path + 1;
	pointer = ft_strchr(pointer, '/');
	pointer++;
	pointer = ft_strchr(pointer, '/');
	return (pointer);
}

/* preenche a struct prompt com as variáveis de ambiente user, hostname e 
path absoluto */
void fill_prompt(t_prompt *prompt)
{
	prompt->user = getenv("USER");
	prompt->hostname = getenv("NAME");
	prompt->path = getenv("PWD");
}

/* Gera a linha do prompt de comando formatada */
char *prompt_concat()
{
	char 	*right_path;
	char	*result;
	t_prompt prompt;

	fill_prompt(&prompt);
	right_path = find_path(prompt.path);
	result = ft_strdup(prompt.user);
	/* Aqui poderia fazer uma função pra concatenar de uma vez só
		mas talvez essa função seja util dessa forma no futuro,
		concat_n_clean é só um strjoin que não deixa o leak de s1 */
	result = concat_and_clean(result, "@");
	result = concat_and_clean(result, prompt.hostname);
	result = concat_and_clean(result, ":~");
	result = concat_and_clean(result, right_path);
	result = concat_and_clean(result, "$ ");
	return (result);
}

void tests()
{	
	char *prompt_string;

	prompt_string = prompt_concat();
	printf("testando se a linha de comando esta sendo formatada corretamente e sem leaks\n");
	printf("%s\n", prompt_string);
	free(prompt_string);
}

int	main(int argc, char *argv[], char *envp[])
{
	tests();
	
	return (0);
}
