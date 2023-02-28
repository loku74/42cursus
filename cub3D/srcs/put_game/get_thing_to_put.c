/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_thing_to_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:04:59 by tibernot          #+#    #+#             */
/*   Updated: 2023/02/28 15:10:19 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_textures	*get_texture_to_put(t_data *d, t_wall wall, t_wall_img *wall_img)
{
	if (wall.orientation == VERTICAL)
	{
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
		if (wall.angle > PI)
			return (d->textures[NO]);
		else
		{
			wall_img->x *= -1;
			return (d->textures[SO]);
		}
	}
}

uint32_t	pixel_to_put(t_wall_img wall_img, t_textures *img)
{
	int	pixel_addr;

	pixel_addr = ((int)((wall_img.y * img->img_height - 1)
				/ wall_img.line_h)) * img->line_length
		+ (int)(wall_img.x * img->img_width)
		* img->bits_per_pixel;
	return (create_trgb(img->addr[pixel_addr], img->addr[pixel_addr + 1], \
	img->addr[pixel_addr + 2], img->addr[pixel_addr + 3]));
}
