/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:36:53 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/24 10:36:55 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_error_message(void)
{
	ft_putstr_color_fd("Error", RED, STDERR_FILENO, TRUE);
}

void	print_file_error_message(char *file)
{
	print_error_message();
	ft_putstr_color_fd(strerror(errno), YELLOW, STDERR_FILENO, FALSE);
	ft_putstr_color_fd(": ", YELLOW, STDERR_FILENO, FALSE);
	ft_putstr_color_fd(file, YELLOW, STDERR_FILENO, TRUE);
}

void	print_args_error_message(int argc)
{
	print_error_message();
	if (argc == 1)
		ft_putstr_color_fd("Pass as an argument a .cub file as the map to load",
			YELLOW, STDERR_FILENO, TRUE);
	else
		ft_putstr_color_fd("Too much arguments", YELLOW, STDERR_FILENO, TRUE);
}

void	print_file_format_error(void)
{
	print_error_message();
	ft_putstr_color_fd("The map must have the .cub extension", \
	YELLOW, STDERR_FILENO, TRUE);
}

t_exit	r_error(char *str)
{
	print_error_message();
	ft_putstr_color_fd(str, YELLOW, STDERR_FILENO, TRUE);
	return (ERROR);
}
