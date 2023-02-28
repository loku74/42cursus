/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:24:16 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/14 14:34:37 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_rays(t_ray *ray_h, t_ray *ray_v, t_player *player)
{
	ray_h->mode = HORIZONTAL;
	ray_v->mode = VERTICAL;
	ray_h->angle = player->angle - (double)(45.00000 * (double)ONE_DEGREE);
	if (ray_h->angle < 0)
		ray_h->angle += (double)PI_2;
	ray_v->angle = ray_h->angle;
}

static void	update_rays(t_ray *ray, t_data *data, int rays, t_player *player)
{
	ray->angle = player->angle - data->angles[rays] + 0.005;
	if (ray->angle < 0)
		ray->angle += (double)PI_2;
	else if (ray->angle > (double)PI_2)
		ray->angle -= (double)PI_2;
}

static void	add_ray(t_data *data, t_ray *ray, double size, int rays)
{
	data->walls[rays].angle = ray->angle;
	data->walls[rays].size = size;
	data->walls[rays].x = ray->x;
	data->walls[rays].y = ray->y;
	data->walls[rays].orientation = ray->mode;
}

static void	create_walls(t_data *data, t_player *player)
{
	int		rays;
	t_ray	ray_h;
	t_ray	ray_v;
	double	dist_h;
	double	dist_v;

	rays = 0;
	set_rays(&ray_h, &ray_v, player);
	while (rays < WINDOW_X)
	{
		dist_h = MAX_RAY_LEN;
		dist_v = MAX_RAY_LEN;
		set_vertical_ray(&ray_v, player);
		dist_v = get_ray_dist(&ray_v, data, player, data->mlx);
		set_horizontal_ray(&ray_h, player);
		dist_h = get_ray_dist(&ray_h, data, player, data->mlx);
		if (dist_v <= dist_h)
			add_ray(data, &ray_v, dist_v, rays);
		else
			add_ray(data, &ray_h, dist_h, rays);
		update_rays(&ray_h, data, rays, player);
		rays++;
		ray_v.angle = ray_h.angle;
	}
}

void	raycasting(t_data *data)
{
	create_walls(data, &data->player);
}
