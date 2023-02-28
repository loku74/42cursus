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
	if (ft_strrcmp(file, ".cub", EXTENSION_LEN) == FALSE)
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
	data->head = create_new_dict();
	if (data->head == NULL)
		return (r_error(MALLOC_ERROR));
	if (check_args_count(argc))
		return (ERROR);
	else if (check_file_format(argv[1]))
		return (ERROR);
	else if (open_file(data, argv[1]))
		return (ERROR);
	else if (get_identifiers(data))
		return (ERROR);
	else if (check_identifiers(data))
		return (ERROR);
	else if (get_map(data))
		return (ERROR);
	else if (check_map(data))
		return (ERROR);
	return (SUCCESS);
}
