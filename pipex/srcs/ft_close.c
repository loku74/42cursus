/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:31:38 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/22 12:10:38 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_close_pipes(t_pipex *pipex)
{
	close(pipex->pipe_1[IN]);
	close(pipex->pipe_1[OUT]);
	close(pipex->pipe_2[IN]);
	close(pipex->pipe_2[OUT]);
}

void	ft_close_fd(t_pipex *pipex)
{
	close(pipex->fd_in);
	close(pipex->fd_out);
}
