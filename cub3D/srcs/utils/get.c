/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:10:05 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/28 14:09:13 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_map_width(t_data *data)
{
	int	i;
	int	width;
	int	len;

	i = 0;
	width = 0;
	while (data->map[i] != NULL)
	{
		len = (int)ft_strlen(data->map[i]);
		if (len > width)
			width = len;
		i++;
	}
	return (width);
}

int	get_map_height(t_data *data)
{
	int	height;

	height = 0;
	while (data->map[height] != NULL)
		height++;
	return (height);
}

double	get_y_nearest(t_player *player, t_ray *ray)
{
	if (ray->angle < PI)
		return ((int)player->y + 1);
	else if (ray->angle > PI)
		return ((int)player->y);
	return (player->y);
}

double	get_x_nearest(t_player *player, t_ray *ray)
{
	if (ray->angle > PI2 AND ray->angle < PI3)
		return ((int)player->x);
	else if (ray->angle < PI2 OR ray->angle > PI3)
		return ((int)player->x + 1);
	return (player->x);
}
