#include "inc/pipex.h"

void	open_files(t_program *program)
{
	program->infile_fd = open(program->infile_name, O_RDONLY);
	program->outfile_fd = open(program->outfile_name, O_WRONLY | O_CREAT | O_TRUNC);
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

void	exec_from_infile(t_program program, char **envp)
{
	close(program.pipe_files[0]);
	dup2(program.pipe_files[1], STDOUT_FILENO);
	dup2(program.infile_fd, STDIN_FILENO);
	if (execve(program.command_paths[0], program.commands[0], envp) == -1)
		free_and_exit(program, "execve failed");
}

void	exec_to_outfile(t_program program, char **envp)
{
	dup2(program.pipe_files[0], STDIN_FILENO);
	close(program.pipe_files[1]);
	dup2(program.outfile_fd, STDOUT_FILENO);
	if (execve(program.command_paths[1], program.commands[1], envp) == -1)
		free_and_exit(program, "execve failed");
}

int	main(int argc, char *argv[], char *envp[])
{
	t_program	program;
	int			id;

	if (argc != 5)
		return (0);
	program = init_struct(argc, argv, envp);
	pipe(program.pipe_files);
	id = fork();
	if (id == -1)
		error_and_exit("fork failed");
	if (id == 0)
	{
		id = fork();
		if (id == 0)
			exec_from_infile(program, envp);
		else
			exec_to_outfile(program, envp);
	}
	close(program.pipe_files[0]);
	close(program.pipe_files[1]);
	waitpid(id, NULL, 0);
	free_split(program.command_paths, argc - 3);
	free_split(program.commands[0], argc - 3);
	free_split(program.commands[1], argc - 3);
	free(program.commands);
}
