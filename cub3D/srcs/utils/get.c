/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:10:05 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/03 19:10:06 by lbourniq         ###   ########.fr       */
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

double	get_y_nearest(t_player *player)
{
	double	y;

	if (player->angle < PI)
	{
		y = ceil(player->y);
		while ((int)y % SCALE != 0)
			y++;
	}
	else
	{
		y = floor(player->y);
		while ((int)y % SCALE != 0)
			y--;
	}
	return (y);
}
