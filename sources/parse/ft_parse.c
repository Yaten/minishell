/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:53:01 by mamaro-d          #+#    #+#             */
/*   Updated: 2022/03/23 15:57:31 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	ft_pipeline();

void	ft_create_cmd(char *line);

void	ft_print();

void	ft_destroy_list();

void	ft_pipe();

static int	ft_find_path(t_node *node)
{
	// char	*path;
	char	**paths;
	char	*path;
	char	*path_slash;
	int		i;

	paths = ft_split(ft_find_value(g_data.array, "PATH"), ':');

	i = -1;
	while (paths[++i])
	{
		path_slash = ft_strjoin(paths[i], "/");
		free(paths[i]);
		path = ft_strjoin(path_slash, node->args[0]);
		free(path_slash);
		if (!access(path, F_OK | X_OK))
		{
			while (paths[++i])
				free(paths[i]);
			free(paths);
			free(node->args[0]);
			node->args[0] = path;
			return (1);
		}
		free(path);
	}
	free(paths);
	return (0);
}

void	ft_parse(char *line, char **envp)
{
	int	index;

	index = 0;
	// init_operators();
	g_data.pipe_count = 0;
	while(line[index] != '\0')
	{
		if (line[index] == '|')
		{
			line[index] = '\0';
			ft_create_cmd(line);
			line += index + 1;
			index = 0;
			g_data.pipe_count++;
		}
		index++;
	}
	ft_create_cmd(line);
	if (ft_builtin())
	ft_pipe();
	(void)envp;
	ft_destroy_list();
}
//1 sucesso na exec da built-in
//0 existe mas deu falha
//-1 nao existe	built-in

void	ft_create_cmd(char *line)
{
	t_node *node;
	t_node *last;

	last = g_data.node;
	node = (t_node *)malloc(sizeof(t_node));
	node->args = ft_split(line, ' ');
	node->relation = g_data.operators[0];
	node->next = NULL;
	node->fd_in = 0;
	node->fd_out = 0;
	if (!ft_find_path(node))
	{
		ft_putstr_fd("Command not found, you r wrong\n", 2);
		return ;
	}
	if(last != NULL)
	{
		while(last->next)
			last = last->next;
		last->next = node;
	}
	else
		g_data.node = node;
}

void	ft_print()
{
	t_node	*tmp;
	int		index;

	tmp = g_data.node;
	while (tmp != NULL)
	{
		index = -1;
		while(tmp->args[++index] != NULL)
			printf("%s %d\n", tmp->args[index], index);
		tmp = tmp->next;
		puts("");
	}
}

void	ft_destroy_list()
{
	t_node *tmp;
	int index;

	tmp = g_data.node;
	while (g_data.node != NULL)
	{
		index = -1;
		while(tmp->args[++index] != NULL)
			free(tmp->args[index]);
		free(tmp->args);
		tmp = g_data.node->next;
		free(g_data.node);
		g_data.node = tmp;
	}
}

void	ft_child_process(int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(g_data.node->args[0], g_data.node->args, g_data.envp);
	// if (execve(g_data.node->args[0], g_data.node->args, g_data.envp) == -1)
}

void	ft_parent_process(int *fd, int pid)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

void	ft_pipe()
{
	int		fd[2];
	pid_t	pid;
	int		fd_in;
	t_node	*tmp;

	if (pipe(fd) == -1)
		ft_putstr_fd("Error: Pipe gonna mad!!!\n", 2);
	fd_in = 0;
	tmp = g_data.node;
	while(tmp)
	{
		pid = fork();
		if(!pid)
		{
			dup2(fd_in, STDIN_FILENO);
			close(fd_in);
			if(g_data.pipe_count)
				dup2(fd[1], STDOUT_FILENO);
			execve(tmp->args[0], tmp->args, g_data.envp);
		}
		else
		{
			waitpid(pid, NULL, 0);
			fd_in = dup(fd[0]);
			if(g_data.pipe_count)
			{
				close(fd[1]);
				pipe(fd);
				g_data.pipe_count--;
			}
			tmp = tmp->next;
		}
	}
	waitpid(pid, NULL, 0);
}

void	ft_pipeline()
{
	int		fd[2];
	pid_t	pid;
	//pid_t	holder;

	if (pipe(fd) == -1)
		ft_putstr_fd("Error: Pipe gonna mad 2\n", 2);
	pid = fork();
	if (pid == -1)
		ft_putstr_fd("Error: Fork gonna mad\n", 2);
	if (!pid)
	{
		ft_child_process(fd);
		/* holder = fork();
		if (holder == -1)
			ft_putstr_fd("Error: Fork gonna mad 2\n", 2);
		if (!holder)

		else
		g_data.node = g_data.node->next; */
	}
	else
		ft_parent_process(fd, pid);
	execve(g_data.node->args[0], g_data.node->args, g_data.envp);

	// g_data.node = g_data.node->next;
	// execve(g_data.node->args[0], g_data.node->args, g_data.envp);
}
