/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:25:25 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/24 10:25:27 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_exit	open_file(t_data *data, char *file)
{
	data->map_fd = open(file, O_RDONLY);
	if (data->map_fd == -1)
	{
		print_file_error_message(file);
		return (ERROR);
	}
	return (SUCCESS);
}

static t_exit	check_file_format(char *file)
{
	if (ft_strrcmp(file, ".cub", 4) == FALSE)
	{
		print_file_format_error();
		return (ERROR);
	}
	return (SUCCESS);
}

static t_exit	check_args_count(int argc)
{
	if (argc != 2)
	{
		print_args_error_message(argc);
		return (ERROR);
	}
	return (SUCCESS);
}

t_exit	parsing(t_data *data, char **argv, int argc)
{
	if (check_args_count(argc))
		return (ERROR);
	if (check_file_format(argv[1]))
		return (ERROR);
	if (open_file(data, argv[1]))
		return (ERROR);
	if (get_identifiers(data))
		return (ERROR);
	if (check_identifiers(data))
		return (ERROR);
	if (check_map(data))
		return (ERROR);
	return (SUCCESS);
}
