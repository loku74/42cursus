/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:24:16 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/30 17:24:17 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	draw_background(t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->img_height * SCALE)
	{
		x = 0;
		while (x < mlx->img_width * SCALE)
		{
			my_pixel_put(mlx, x, y, 0x766C7F);
			x++;
		}
		y++;
	}
}

static void	draw_map(t_data *data, t_mlx *mlx)
{
	int	y;
	int	x;

	y = 0;
	while (y < mlx->img_height * SCALE)
	{
		x = 0;
		while (x < mlx->img_width * SCALE && x < (int)ft_strlen(data->map[y / SCALE]) * SCALE)
		{
			if (y % SCALE > 1 AND x % SCALE > 1 AND data->map[y / SCALE][x / SCALE] == '1')
				my_pixel_put(mlx, x, y, 0x153131);
			else if (y % SCALE > 1 AND x % SCALE > 1 AND data->map[y / SCALE][x / SCALE] == '0')
				my_pixel_put(mlx, x, y, 0xEABDA8);
			else if (y % SCALE > 1 AND x % SCALE > 1 AND is_in(data->map[y / SCALE][x / SCALE], PLAYER_SPAWN))
				my_pixel_put(mlx, x, y, 0x548C2F);
			else if (y % SCALE > 1 AND x % SCALE > 1 AND data->map[y / SCALE][x / SCALE] == ' ')
				my_pixel_put(mlx, x, y, 0xC2F8CB);
			else
				my_pixel_put(mlx, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_player player, t_mlx *mlx)
{
	int	x;
	int y;

	y = 0;
	while (y <= SCALE - PLAYER_SCALE * 2)
	{
		x = 0;
		while (x <= SCALE - PLAYER_SCALE * 2)
		{
			my_pixel_put(mlx, player.x + x, player.y + y, 0xFFFF00);
			x++;
		}
		y++;
	}
}

static void	draw_ray(t_mlx *mlx, t_ray *ray)
{
	int x;
	int y;

	if (ray->x < 0 OR ray->y < 0)
		return ;
	if (ray->x > mlx->img_width * SCALE OR ray->y > mlx->img_height * SCALE) {
		return ;
	}
	x = 0;
	y = 0;
	while (y < 14)
	{
		while (x < 14)
		{
			my_pixel_put(mlx, ray->x + y ,ray->y + x, 0xFF0000);
			x++;
		}
		y++;
	}
}

static void	draw_ray_angle(t_data *data, t_mlx *mlx, t_player *player)
{
	double 	x;
	double	y;
	int 	index;
	int 	rays;
	t_ray	ray;

	rays = 0;
	ray.angle = player->angle;
	index = 0;
	while (rays < 1)
	{
		if (set_horizontal_ray(&ray, player))
		{
			while (index < mlx->img_width)
			{
				x = ray.x / SCALE;
				y = ray.y / SCALE;
				if (y >= 0 AND x >= 0 AND y < mlx->img_height AND x < mlx->img_width)
				{
					printf("x: %f\n", x);
					printf("y: %f\n", y);
					if (data->map[(int)y][(int)x] == '1')
						break;
					else
					{
						ray.x += ray.xo;
						ray.y += ray.yo;
					}
				}
				index++;
			}
		}
		rays++;
	}
	printf("ray x: %f\n", ray.x);
	printf("ray y: %f\n", ray.y);
	draw_ray(mlx, &ray);
}

void	draw_2d(t_data *data, t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	draw_background(mlx);
	draw_map(data, mlx);
	draw_player(data->player, mlx);
	draw_ray_angle(data, data->mlx, &data->player);
	printf("player x: %f\n", data->player.x);
	printf("player y: %f\n", data->player.y);
	printf("player angle: %f\n", data->player.angle);
	mlx_put_image_to_window(mlx->mlx, mlx->win,mlx->img, 0, 0);
}
