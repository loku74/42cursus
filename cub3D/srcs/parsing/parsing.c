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
		clear_dict(data->head);
		print_file_error_message(file);
		return (ERROR);
	}
	return (SUCCESS);
}

static t_exit	check_file_format(t_data *data, char *file)
{
	if (ft_strrcmp(file, ".cub", EXTENSION_LEN) == FALSE)
	{
		print_file_format_error();
		clear_dict(data->head);
		return (ERROR);
	}
	return (SUCCESS);
}

static t_exit	check_args_count(t_data *data, int argc)
{
	if (argc != 2)
	{
		print_args_error_message(argc);
		clear_dict(data->head);
		return (ERROR);
	}
	return (SUCCESS);
}

t_exit	parsing(t_data *data, char **argv, int argc)
{
	if (check_args_count(data, argc))
		return (ERROR);
	if (check_file_format(data, argv[1]))
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
