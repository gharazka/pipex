/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:48:24 by gharazka          #+#    #+#             */
/*   Updated: 2024/07/31 21:48:25 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/libft/inc/libft.h"
# include "sys/wait.h"
# include <stdio.h>
# include "errno.h"

typedef struct s_program
{
	int		pipe_files[2];
	char	*infile_name;
	char	*outfile_name;
	int		infile_fd;
	int		outfile_fd;
	char	***commands;
	char	**command_paths;
}	t_program;

void	get_command_path(char **envp, int i, t_program *program, char *argv[]);
char	**get_path(char *envp[]);
void	free_and_exit(t_program program, char *message);
void	free_split(char **array, int len);
void	error_and_exit(char *message);

#endif
