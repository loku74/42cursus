/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:09:52 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/13 15:54:42 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_exit	set_mlx(t_data *data, t_mlx *mlx)
{
	mlx->img_width = get_map_width(data);
	mlx->img_height = get_map_height(data);
	mlx->win = mlx_new_window(mlx->mlx, WINDOW_X, \
	WINDOW_Y, WINDOW_NAME);
	if (mlx->win == NULL)
		return (r_error(MLX_WIN_FAIL));
	data->floor_color = create_trgb(data->colors[FLOOR][B], \
	data->colors[FLOOR][G], data->colors[FLOOR][R], 0);
	data->ceiling_color = create_trgb(data->colors[CEILING][B], \
	data->colors[CEILING][G], data->colors[CEILING][R], 0);
	return (SUCCESS);
}

t_exit	set_walls(t_data *data)
{
	double	i;
	double	window_half;

	data->walls = (t_wall *)malloc(sizeof(t_wall) * WINDOW_X);
	data->angles = (double *)malloc(sizeof(double) * WINDOW_X);
	if (data->walls == NULL OR data->angles == NULL)
	{
		free_all(data);
		return (r_error(MALLOC_ERROR));
	}
	i = 0;
	window_half = (double)WINDOW_X / 2;
	while (i < WINDOW_X)
	{
		data->angles[(int)i] = atan((window_half - (i + 1)) / window_half);
		i++;
	}
	return (SUCCESS);
}

void	set_all(t_data *data, t_mlx *mlx)
{
	data->head = NULL;
	data->mlx = NULL;
	data->walls = NULL;
	data->angles = NULL;
	data->textures = NULL;
	data->colors = NULL;
	data->map = NULL;
	mlx->mlx = NULL;
	mlx->win = NULL;
	data->img_walls = NULL;
	data->img_background = NULL;
}
