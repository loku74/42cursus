/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:16:50 by ratinax           #+#    #+#             */
/*   Updated: 2023/02/28 16:34:10 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	put_wall_line(t_data *d, t_wall wall, int x, t_wall_img wall_img)
{
	double	up_of_line;
	int		y;

	wall_img.img = get_texture_to_put(d, wall, &wall_img);
	wall.size *= cos(d->player.angle - wall.angle);
	wall_img.line_h = WINDOW_Y / wall.size;
	up_of_line = (WINDOW_Y - wall_img.line_h) >> 1;
	put_background(d, wall_img.line_h, up_of_line, x);
	if (up_of_line < 0)
		wall_img.y = -up_of_line;
	else
		wall_img.y = 0;
	wall_img.x = 1 + wall_img.x - floor(1 + wall_img.x);
	y = up_of_line + wall_img.y;
	while (wall_img.y < wall_img.line_h && y < WINDOW_Y)
	{
		my_pixel_put(d->img_background, x, \
		y, pixel_to_put(wall_img, wall_img.img));
		wall_img.y++;
		y++;
	}
}

static void	next_ray(t_data *d, int *i, t_wall_img *wall_img, double diff)
{
	wall_img->x = diff;
	put_wall_line(d, d->walls[*i], *i, *wall_img);
	(*i)++;
}

void	put_wall_lines(t_data *d, t_wall_img *wall_img, int *i)
{
	static int	window_x = WINDOW_X - 1;

	if ((*i < window_x) && d->walls[*i].x == d->walls[*i + 1].x)
	{
		while ((*i < window_x) && (d->walls[*i].x == d->walls[*i + 1].x))
			next_ray(d, i, wall_img, d->walls[*i].y
				- floor(d->walls[*i].y));
	}
	else
	{
		while ((*i < window_x) && (d->walls[*i].y == d->walls[*i + 1].y))
			next_ray(d, i, wall_img, d->walls[*i].x
				- floor(d->walls[*i].x));
	}
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
