/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:21:50 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/22 12:17:32 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_execute_cmds(t_pipex *pipex, char **argv, int i)
{
	int		k;
	char	**cmd_args;
	char	*cmd;
	char	*temp;

	k = 0;
	while (pipex->paths[k])
	{
		if (is_in(argv[i + 2], "\"\'{}") == 1)
			cmd_args = ft_pipex_split(argv[i + 2]);
		else
			cmd_args = ft_split(argv[i + 2], ' ');
		temp = ft_strdup(ft_pipex_strrchr(cmd_args[0], '/'));
		free(cmd_args[0]);
		cmd_args[0] = temp;
		cmd = ft_strjoin(pipex->paths[k], cmd_args[0]);
		execve(cmd, cmd_args, pipex->envp);
		free(cmd);
		ft_free_cmds(cmd_args);
		k++;
	}
}

static void	ft_exec(t_pipex *pipex, char **argv, int i)
{
	ft_close_pipes(pipex);
	ft_close_fd(pipex);
	ft_execute_cmds(pipex, argv, i);
	ft_putstr_fd("Command not found: ", STDERR_FILENO);
	ft_putendl_fd(argv[i + 2], STDERR_FILENO);
	exit(errno);
}

static void	ft_set_fd(t_pipex *pipex, int argc, int i)
{
	if (i == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		dup2(pipex->pipe_1[OUT], STDOUT_FILENO);
	}
	else if (i == argc - 4)
	{
		if (i % 2 == 0)
			dup2(pipex->pipe_2[IN], STDIN_FILENO);
		else
			dup2(pipex->pipe_1[IN], STDIN_FILENO);
		dup2(pipex->fd_out, STDOUT_FILENO);
	}
	else if (i % 2 == 0)
	{
		dup2(pipex->pipe_2[IN], STDIN_FILENO);
		dup2(pipex->pipe_1[OUT], STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->pipe_1[IN], STDIN_FILENO);
		dup2(pipex->pipe_2[OUT], STDOUT_FILENO);
	}
}

void	ft_init_fd(t_pipex *pipex, char **argv, int i, int argc)
{
	if (i == 0 && pipex->fd_in == -1)
		exit(errno);
	if (i == argc - 4 && pipex->fd_out == -1)
		exit(errno);
	ft_set_fd(pipex, argc, i);
	ft_exec(pipex, argv, i);
}
