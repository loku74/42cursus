/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:53:13 by ratinax           #+#    #+#             */
/*   Updated: 2023/02/28 11:24:01 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_textures(t_data *d)
{
	d->textures[NO]->addr = mlx_get_data_addr(d->textures[NO]->img,
			&(d->textures[NO]->bits_per_pixel), &(d->textures[NO]->line_length),
			&(d->textures[NO]->endian));
	d->textures[SO]->addr = mlx_get_data_addr(d->textures[SO]->img,
			&(d->textures[SO]->bits_per_pixel), &(d->textures[SO]->line_length),
			&(d->textures[SO]->endian));
	d->textures[WE]->addr = mlx_get_data_addr(d->textures[WE]->img,
			&(d->textures[WE]->bits_per_pixel), &(d->textures[WE]->line_length),
			&(d->textures[WE]->endian));
	d->textures[EA]->addr = mlx_get_data_addr(d->textures[EA]->img,
			&(d->textures[EA]->bits_per_pixel), &(d->textures[EA]->line_length),
			&(d->textures[EA]->endian));
	d->textures[NO]->bits_per_pixel = d->textures[NO]->bits_per_pixel >> 3;
	d->textures[SO]->bits_per_pixel = d->textures[SO]->bits_per_pixel >> 3;
	d->textures[EA]->bits_per_pixel = d->textures[EA]->bits_per_pixel >> 3;
	d->textures[WE]->bits_per_pixel = d->textures[WE]->bits_per_pixel >> 3;
	d->textures[NO]->max_addr = d->textures[NO]->img_width * \
	d->textures[NO]->img_height * d->textures[NO]->bits_per_pixel;
	d->textures[SO]->max_addr = d->textures[SO]->img_width * \
	d->textures[SO]->img_height * d->textures[SO]->bits_per_pixel;
	d->textures[EA]->max_addr = d->textures[EA]->img_width * \
	d->textures[EA]->img_height * d->textures[EA]->bits_per_pixel;
	d->textures[WE]->max_addr = d->textures[WE]->img_width * \
	d->textures[WE]->img_height * d->textures[WE]->bits_per_pixel;
}

t_img	*init_img(t_data *d, int width, int height)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (r_error(MALLOC_ERROR), NULL);
	img->img = mlx_new_image(d->mlx->mlx, width, height);
	if (!img->img)
		return (free(img), r_error(MLX_IMG_FAIL), NULL);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->bits_per_pixel = img->bits_per_pixel >> 3;
	return (img);
}

int	init_imgs(t_data *d)
{
	d->img_background = init_img(d, WINDOW_X, WINDOW_Y);
	if (!d->img_background)
		return (ERROR);
	d->img_walls = init_img(d, WINDOW_X, WINDOW_Y);
	if (!d->img_walls || !d->textures[NO]
		|| !d->textures[SO] || !d->textures[WE] || !d->textures[EA])
		return (ERROR);
	init_textures(d);
	return (SUCCESS);
}

void	init_background(t_data *d)
{
	int	x;
	int	y;
	int	half_window_y;

	y = 0;
	half_window_y = WINDOW_Y >> 1;
	while (y < half_window_y - 1)
	{
		x = -1;
		while (++x < WINDOW_X - 1)
		{
			my_pixel_put(d->img_background, x, y, d->ceiling_color);
			my_pixel_put(d->img_background, x, y + half_window_y,
				d->floor_color);
		}
		y++;
	}
}
