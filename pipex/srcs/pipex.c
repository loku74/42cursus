/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:08:34 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/17 09:06:01 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	pipex.envp = envp;
	pipex.pids = NULL;
	if (argc >= 5)
	{
		ft_check_files_error(&pipex, argc, argv);
		ft_create_paths(&pipex, envp);
		ft_create_forks(&pipex, argc, argv);
		ft_close_pipes(&pipex);
		close(pipex.fd_out);
		close(pipex.fd_in);
		i = 0;
		while (i < argc - 3)
		{
			waitpid(pipex.pids[i], NULL, 0);
			i++;
		}
		ft_free_paths(pipex.paths);
		free(pipex.pids);
	}
	return (0);
}
