/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratinax <ratinax@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:16:50 by ratinax           #+#    #+#             */
/*   Updated: 2023/03/01 12:21:48 by ratinax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	set_wall_img(t_wall_img *wall_img, t_wall wall, t_data *d)
{
	wall_img->img = get_texture_to_put(d, wall, wall_img);
	wall_img->line_h = WINDOW_Y / wall.size;
	wall_img->up_of_line = (WINDOW_Y - wall_img->line_h) >> 1;
	if (wall_img->up_of_line < 0)
		wall_img->y = -wall_img->up_of_line;
	else
		wall_img->y = 0;
	wall_img->x = wall_img->x - floor(wall_img->x);
}

static void	put_wall_line(t_data *d, t_wall wall, int x, t_wall_img wall_img)
{
	int		y;
	double	pixel_addr;
	int		pixel_addr_x;
	double	incr;

	wall.size *= cos(d->player.angle - wall.angle);
	set_wall_img(&wall_img, wall, d);
	put_background(d, wall_img.line_h, wall_img.up_of_line, x);
	pixel_addr_x = ((int)(wall_img.x * wall_img.img->img_width)) \
	* wall_img.img->bits_per_pixel;
	pixel_addr = pixel_addr_x;
	y = wall_img.up_of_line + wall_img.y;
	incr = (double)wall_img.img->img_height / (double)wall_img.line_h;
	while (wall_img.y < wall_img.line_h && y < WINDOW_Y)
	{
		my_pixel_put(d->img_background, x, \
		y, pixel_to_put(wall_img.img, pixel_addr));
		pixel_addr = ((int)((double)wall_img.y * (double)incr)) \
		* wall_img.img->line_length + pixel_addr_x;
		wall_img.y++;
		y++;
	}
}

static void	next_ray(t_data *d, int *i, t_wall_img *wall_img)
{
	put_wall_line(d, d->walls[*i], *i, *wall_img);
	(*i)++;
}

void	put_wall_lines(t_data *d, t_wall_img *wall_img, int *i)
{
	static int	window_x = WINDOW_X - 1;

	while (*i < window_x)
		next_ray(d, i, wall_img);
}

void	put_walls(t_data *d)
{
	int			i;
	t_wall_img	wall_img;

	i = 0;
	wall_img.x = 0;
	while (i < WINDOW_X)
	{
		put_wall_lines(d, &wall_img, &i);
		put_wall_line(d, d->walls[i], i, wall_img);
		i++;
	}
	mlx_put_image_to_window(d->mlx->mlx, d->mlx->win, d->img_background->img,
		0, 0);
}
