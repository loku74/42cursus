/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:12:55 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 15:53:37 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_create_paths(t_pipex *pipex, char **envp)
{
	int		i;
	char	**paths;
	char	*temp;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) != NULL)
			paths = ft_split(envp[i] + ft_strlen("PATH="), ':');
		i++;
	}
	i = 0;
	while (paths[i])
	{
		temp = paths[i];
		paths[i] = ft_strjoin(temp, "/");
		free(temp);
		i++;
	}
	pipex->paths = paths;
}

static void	init_pipes(t_pipex *pipex)
{
	if (pipe(pipex->pipe_1) == -1)
		ft_exit(pipex);
	if (pipe(pipex->pipe_2) == -1)
		ft_exit(pipex);
}

static void	reset_pipe(t_pipex *pipex, int i)
{
	if (i % 2 == 0)
	{
		close(pipex->pipe_1[IN]);
		close(pipex->pipe_1[OUT]);
		if (pipe(pipex->pipe_1) == -1)
			ft_exit(pipex);
	}
	else
	{
		close(pipex->pipe_2[IN]);
		close(pipex->pipe_2[OUT]);
		if (pipe(pipex->pipe_2) == -1)
			ft_exit(pipex);
	}
}

void	ft_create_forks(t_pipex *pipex, int argc, char **argv)
{
	int	*pids;
	int	i;

	pids = (int *)malloc(sizeof(int) * (argc - 3));
	if (pids == NULL)
		ft_exit(pipex);
	init_pipes(pipex);
	i = 0;
	while (i < argc - 3)
	{
		if (i >= 2)
			reset_pipe(pipex, i);
		pids[i] = fork();
		if (pids[i] == -1)
			ft_exit(pipex);
		else if (pids[i] == 0)
			ft_init_fd(pipex, argv, i, argc);
		i++;
	}
	pipex->pids = pids;
}
