/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:09:36 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/03 19:09:37 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_bool	set_horizontal_ray(t_ray *ray, t_player *player)
{
	if (ray->angle == 0 OR ray->angle == PI)
	{
		ray->x = player->x;
		ray->y = player->y;
		return (FALSE);
	}
	else if (ray->angle > PI)
	{
		ray->y = get_y_nearest(player) - 0.000000001;
		ray->x = (player->y - ray->y) * (-1 / tan(ray->angle)) + player->x;
		ray->yo = -SCALE;
		ray->xo = -ray->yo * (-1 / tan(ray->angle));
	}
	else if (ray->angle < PI)
	{
		ray->y = get_y_nearest(player);
		ray->x = (player->y - ray->y) * (-1 / tan(ray->angle)) + player->x;
		ray->yo = SCALE;
		ray->xo = -ray->yo * (-1 / tan(ray->angle));
	}
	return (TRUE);
}
