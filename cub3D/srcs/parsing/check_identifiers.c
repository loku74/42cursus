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

static t_exit	parse_rgb(t_data *data, char *colors, int texture)
{
	char	**color_set;
	int		i;

	color_set = ft_split(colors, ',');
	if (color_set == NULL)
	{
		free_textures(data, N_TEXTURES, TRUE);
		free_colors(data);
		return (r_error(MALLOC_ERROR));
	}
	i = 0;
	while (i < RGB_CONSTANT)
	{
		if (len_split(color_set) != 3 OR check_num(color_set[i]))
		{
			free_textures(data, N_TEXTURES, TRUE);
			free_colors(data);
			free_split(color_set);
			return (r_error(RGB_ERROR));
		}
		else
			data->colors[texture][i] = ft_atoi(color_set[i]);
		i++;
	}
	return (free_split(color_set), SUCCESS);
}

static t_exit	treat_identifiers(t_data *data, t_mlx *mlx)
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
			data->textures[i] = mlx_xpm_file_to_image(mlx->mlx, \
			value, &mlx->img_width, &mlx->img_height);
			if (data->textures[i] == NULL)
			{
				free_textures(data, i, TRUE);
				return (r_error(IMG_ERROR));
			}
		}
		else if (check_rgb(value) OR parse_rgb(data, value, i - N_TEXTURES))
			return (free_textures(data, N_TEXTURES, TRUE), ERROR);
		i++;
	}
	return (SUCCESS);
}

t_exit	check_identifiers(t_data *data)
{
	if (set_textures(data) OR set_colors(data))
	{
		clear_dict(data->head);
		return (r_error(MALLOC_ERROR));
	}
	else if (len_dict(data->head) != N_IDENTIFIERS)
	{
		clear_dict(data->head);
		free_textures(data, N_TEXTURES, FALSE);
		free_colors(data);
		return (r_error(MISSING_IDS));
	}
	else if (treat_identifiers(data, data->mlx))
	{
		clear_dict(data->head);
		free_colors(data);
		return (ERROR);
	}
	return (SUCCESS);
}
