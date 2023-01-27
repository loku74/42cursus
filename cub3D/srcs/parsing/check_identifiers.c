/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:22:30 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/26 10:22:31 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_exit	set_textures(t_data *data)
{
	data->textures = (void **)malloc(sizeof(void *) * N_TEXTURES);
	if (data->textures == NULL)
		return (ERROR);
	return (SUCCESS);
}

static t_exit	set_colors(t_data *data)
{
	data->colors = (int **)malloc(sizeof(int *) * N_COLORS);
	if (data->colors == NULL)
	{
		free_textures(data, N_TEXTURES, FALSE);
		return (ERROR);
	}
	data->colors[FLOOR] = (int *)malloc(sizeof(int) * RGB_CONSTANT);
	if (data->colors[FLOOR] == NULL)
	{
		free_textures(data, N_TEXTURES, FALSE);
		free(data->colors);
		return (ERROR);
	}
	data->colors[CEILING] = (int *)malloc(sizeof(int) * RGB_CONSTANT);
	if (data->colors[CEILING] == NULL)
	{
		free_textures(data, N_TEXTURES, FALSE);
		free(data->colors[FLOOR]);
		free(data->colors);
		return (ERROR);
	}
	return (SUCCESS);
}

static t_exit	parse_rgb_colors(t_data *data, char *colors, int texture)
{
	char	**color_set;
	int		i;

	color_set = ft_split(colors, ',');
	if (color_set == NULL)
	{
		free_textures(data, N_TEXTURES, TRUE);
		free_colors(data);
		return (r_error("Malloc error"));
	}
	i = 0;
	while (i < RGB_CONSTANT)
	{
		if (check_num(color_set[i]) || len_split(color_set) != 3)
		{
			free_textures(data, N_TEXTURES, TRUE);
			free_colors(data);
			free_split(color_set);
			return (r_error("Invalid RGB input"));
		}
		else
			data->colors[texture][i] = ft_atoi(color_set[i]);
		i++;
	}
	return (free_split(color_set), SUCCESS);
}

static t_exit	treat_identifiers(t_data *data)
{
	static char	*ids[N_IDENTIFIERS] = {"NO", "SO", "WE", "EA", "F", "C"};
	char		*value;
	int			i;

	i = 0;
	while (i < N_IDENTIFIERS)
	{
		value = get_value(data->head, ids[i]);
		if (i <= 3)
		{
			data->textures[i] = mlx_xpm_file_to_image(data->mlx, \
			value, &data->img_width, &data->img_height);
			if (data->textures[i] == NULL)
			{
				free_textures(data, i, TRUE);
				free_colors(data);
				return (r_error("Path to image not valid or wrong extension"));
			}
		}
		else if (parse_rgb_colors(data, value, i - N_TEXTURES))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

t_exit	check_identifiers(t_data *data)
{
	if (set_textures(data) || set_colors(data))
	{
		clear_dict(data->head);
		return (r_error("Malloc error"));
	}
	if (len_dict(data->head) != N_IDENTIFIERS || treat_identifiers(data))
	{
		clear_dict(data->head);
		return (ERROR);
	}
	return (SUCCESS);
}
