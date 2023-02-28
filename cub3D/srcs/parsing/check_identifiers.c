/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:22:30 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/21 17:33:39 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_exit	set_textures(t_data *data)
{
	int	i;

	i = 0;
	data->textures = malloc(sizeof(t_textures) * N_TEXTURES);
	if (data->textures == NULL)
		return (ERROR);
	while (i < N_TEXTURES)
	{
		data->textures[i] = NULL;
		i++;
	}
	i = 0;
	while (i < N_TEXTURES)
	{
		data->textures[i] = malloc(sizeof(t_textures));
		if (data->textures[i] == NULL)
			return (ERROR);
		i++;
	}
	i = -1;
	while (++i < N_TEXTURES)
		data->textures[i]->img = NULL;
	return (SUCCESS);
}

static t_exit	set_colors(t_data *data)
{
	data->colors = (int **)malloc(sizeof(int *) * N_COLORS);
	if (data->colors == NULL)
		return (ERROR);
	data->colors[FLOOR] = NULL;
	data->colors[CEILING] = NULL;
	data->colors[FLOOR] = (int *)malloc(sizeof(int) * RGB_CONSTANT);
	if (data->colors[FLOOR] == NULL)
		return (ERROR);
	data->colors[CEILING] = (int *)malloc(sizeof(int) * RGB_CONSTANT);
	if (data->colors[CEILING] == NULL)
		return (ERROR);
	return (SUCCESS);
}

static t_exit	parse_rgb(t_data *data, char *colors, int texture)
{
	char	**color_set;
	int		i;

	color_set = ft_split(colors, ",");
	if (color_set == NULL)
		return (r_error(MALLOC_ERROR));
	i = 0;
	while (i < RGB_CONSTANT)
	{
		if (len_split(color_set) != 3 OR check_num(color_set[i]))
		{
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
			data->textures[i]->img = mlx_xpm_file_to_image(mlx->mlx, \
			value, &data->textures[i]->img_width, \
			&data->textures[i]->img_height);
			if (data->textures[i]->img == NULL)
				return (r_error(IMG_ERROR));
		}
		else if (check_rgb(value) OR parse_rgb(data, value, i - N_TEXTURES))
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

t_exit	check_identifiers(t_data *data)
{
	if (len_dict(data->head) != N_IDENTIFIERS)
		return (r_error(MISSING_IDS));
	else if (set_colors(data))
		return (r_error(MALLOC_ERROR));
	else if (set_textures(data))
		return (r_error(MALLOC_ERROR));
	else if (treat_identifiers(data, data->mlx))
		return (ERROR);
	return (SUCCESS);
}
