/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:46:47 by gharazka          #+#    #+#             */
/*   Updated: 2024/07/31 21:46:47 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	error_and_exit(char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	free_split(char **array, int len)
{
	int	i;

	i = 0;
	if (len == 0)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			free(array[i]);
			i++;
		}
	}
	free(array);
}

void	free_and_exit(t_program program, char *message)
{
	if (program.command_paths[1])
		free_split(program.command_paths, 2);
	else
		free_split(program.command_paths, 1);
	free_split(program.commands[0], 2);
	if (program.commands[1])
		free_split(program.commands[1], 2); //to change later
	free(program.commands);
	error_and_exit(message);
}

char	**get_path(char *envp[])
{
	int		i;
	char	*pathline;
	char	**path;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			pathline = (ft_strnstr(envp[i], "PATH=", 5) + 5);
		}
		i++;
	}
	if (!pathline)
		perror("command not found");
	path = ft_split(pathline, ':');
	if (!path)
		error_and_exit("malloc failed");
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/", 1);
		i++;
	}
	return (path);
}

void	get_command_path(char **envp, int i, t_program *program, char *argv[])
{
	int		j;
	char	**path;

	j = 0;
	path = get_path(envp);
	program->commands[i - 2] = ft_split(argv[i], ' ');
	while (path[j])
	{
		program->command_paths[i - 2] = ft_strjoin(path[j],
				program->commands[i - 2][0], 0);
		if (access(program->command_paths[i - 2], X_OK) == 0)
		{
			free_split(path, 0);
			return ;
		}
		j++;
		if (path[j])
			free(program->command_paths[i - 2]);
	}
	free_split(path, 0);
	perror("command not found");
}
