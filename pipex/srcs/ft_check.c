/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:21:38 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/09 10:27:28 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_display_error(int errnum, char *content)
{
	ft_putstr_fd(strerror(errnum), STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(content, STDERR_FILENO);
}

void	ft_check_files_error(t_pipex *pipex, int argc, char **argv)
{
	pipex->fd_in = open(argv[1], O_RDONLY);
	if (pipex->fd_in == -1)
		ft_display_error(errno, argv[1]);
	pipex->fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out == -1)
		ft_display_error(errno, argv[argc - 1]);
}
