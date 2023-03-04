/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_thing_to_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:04:59 by tibernot          #+#    #+#             */
/*   Updated: 2023/03/01 12:05:12 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_textures	*get_texture_to_put(t_data *d, t_wall wall, t_wall_img *wall_img)
{
	if (wall.orientation == VERTICAL)
	{
		wall_img->x = wall.y;
		if (wall.angle > PI2 && wall.angle < PI3)
		{
			wall_img->x *= -1;
			return (d->textures[WE]);
		}
		else
			return (d->textures[EA]);
	}
	else
	{
		wall_img->x = wall.x;
		if (wall.angle > PI)
			return (d->textures[NO]);
		else
		{
			wall_img->x *= -1;
			return (d->textures[SO]);
		}
	}
}

uint32_t	pixel_to_put(t_textures *img, int pixel_addr)
{
	return (create_trgb(img->addr[pixel_addr], img->addr[pixel_addr + 1], \
	img->addr[pixel_addr + 2], img->addr[pixel_addr + 3]));
}
