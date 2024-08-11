/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:47:01 by gharazka          #+#    #+#             */
/*   Updated: 2024/07/31 21:48:12 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/pipex.h"

void	open_files(t_program *program)
{
	program->infile_fd = open(program->infile_name, O_RDONLY, 0444);
	program->outfile_fd = open(program->outfile_name,
			O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (program->infile_fd == -1 || program->outfile_fd == -1)
		perror("open failed");
}

t_program	init_struct(int argc, char *argv[], char *envp[])
{
	t_program	program;
	int			i;

	i = 2;
	program.infile_name = argv[1];
	program.outfile_name = argv[argc - 1];
	open_files(&program);
	program.commands = (char ***)malloc(sizeof(char **) * argc - 3);
	if (!program.commands)
		error_and_exit("malloc failed");
	program.command_paths = (char **)malloc(sizeof(char *) * argc - 3);
	if (!program.command_paths)
		error_and_exit("malloc failed");
	program.command_paths[1] = NULL;
	program.commands[1] = NULL; //to change
	while (i < argc - 1)
	{
		get_command_path(envp, i, &program, argv);
		i++;
	}
	return (program);
}

void	execute_last(t_program program, char **envp, int i)
{
	if (execve(program.command_paths[i - 1], program.commands[i - 1], envp) == -1)
		free_and_exit(program, "execve failed");
}

void	execute(t_program program, char **envp, int i)
{
	int	id;
	int	fd[2];

	pipe(fd);
	id = fork();
	if (id == -1)
		error_and_exit("fork failed");
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (execve(program.command_paths[i - 1], program.commands[i - 1], envp) == -1)
			perror("execve failed");
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_program	program;
	int			i;

	i = 1;
	if (argc != 5)
		return (0);
	program = init_struct(argc, argv, envp);
	dup2(program.infile_fd, STDIN_FILENO);
	while (i < (argc - 3))
	{
		execute(program, envp, i);
		i++;
	}
	dup2(program.outfile_fd, STDOUT_FILENO);
	execute_last(program, envp, i);
	close(program.pipe_files[0]);
	close(program.pipe_files[1]);
	close(program.infile_fd);
	close(program.outfile_fd);
	free_split(program.command_paths, argc - 3);
	free_split(program.commands[0], argc - 3);
	free_split(program.commands[1], argc - 3);
	free(program.commands);
}

