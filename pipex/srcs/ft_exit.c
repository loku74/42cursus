/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 09:34:45 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/08 15:53:43 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit(t_pipex *pipex)
{
	if (pipex->pids != NULL)
		free(pipex->pids);
	ft_free_paths(pipex->paths);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	exit(errno);
}
