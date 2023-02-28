/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:09:36 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/28 14:10:47 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	set_horizontal_ray(t_ray *ray, t_player *player)
{
	if (ray->angle > PI)
	{
		ray->y = get_y_nearest(player, ray) - 0.00000001;
		ray->x = (player->y - ray->y) * (-1 / tan(ray->angle)) + player->x;
		ray->yo = -1;
		ray->xo = -ray->yo * (-1 / tan(ray->angle));
	}
	else if (ray->angle < PI)
	{
		ray->y = get_y_nearest(player, ray);
		ray->x = (player->y - ray->y) * (-1 / tan(ray->angle)) + player->x;
		ray->yo = 1;
		ray->xo = -ray->yo * (-1 / tan(ray->angle));
	}
	else
	{
		ray->x = player->x;
		ray->y = player->y;
	}
}

void	set_vertical_ray(t_ray *ray, t_player *player)
{
	if (ray->angle > (double) PI2 AND ray->angle < (double) PI3)
	{
		ray->x = get_x_nearest(player, ray) - 0.0000001;
		ray->y = (player->x - ray->x) * -tan(ray->angle) + player->y;
		ray->xo = -1;
		ray->yo = -ray->xo * -tan(ray->angle);
	}
	else if (ray->angle < (double) PI2 OR ray->angle > (double) PI3)
	{
		ray->x = get_x_nearest(player, ray);
		ray->y = (player->x - ray->x) * -tan(ray->angle) + player->y;
		ray->xo = 1;
		ray->yo = -ray->xo * -tan(ray->angle);
	}
	else
	{
		ray->x = player->x;
		ray->y = player->y;
	}
}
