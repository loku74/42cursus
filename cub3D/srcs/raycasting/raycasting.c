/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:19:53 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/28 13:20:39 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static double	len_ray(double x1, double y1, double x2, double y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

static double	get_dist(t_player *player, t_ray *ray, t_mlx *mlx, t_data *data)
{
	double	x;
	double	y;

	x = ray->x;
	y = ray->y;
	if (y >= 0 AND x >= 0 AND y < mlx->img_height AND x < mlx->img_width)
	{
		if ((int)ft_strlen(data->map[(int)y]) > (int)x \
			AND data->map[(int)y][(int)x] == '1')
			return (len_ray(player->x, player->y, ray->x, ray->y));
		else
		{
			ray->y += ray->yo;
			ray->x += ray->xo;
		}
	}
	return (MAX_RAY_LEN);
}

static int	get_max_index(t_ray *ray, t_mlx *mlx)
{
	if (ray->mode == VERTICAL)
		return (mlx->img_width);
	else
		return (mlx->img_height);
}

double	get_ray_dist(t_ray *ray, t_data *data, t_player *player, t_mlx *mlx)
{
	double	dist;
	int		index;
	int		max_index;

	dist = MAX_RAY_LEN;
	max_index = get_max_index(ray, mlx);
	index = 0;
	while (index < max_index)
	{
		dist = get_dist(player, ray, mlx, data);
		if (dist != MAX_RAY_LEN)
			break ;
		index++;
	}
	return (dist);
}
