/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:44:32 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/19 17:49:52 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_in(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static void	add_to_window(t_mlx *mlx, void *img, int x, int y)
{
	mlx_put_image_to_window(
		mlx->mlx,
		mlx->win,
		img,
		x * mlx->pixel,
		y * mlx->pixel);
}

static void	check_wall(t_mlx *mlx, int x, int y)
{
	if ((x == 0 || x == mlx->map_width - 1) && y != mlx->map_height - 1)
		add_to_window(mlx, mlx->wall, x, y);
	else if (y == mlx->map_height - 1 && x == 0)
		add_to_window(mlx, mlx->grass, x, y);
	else if ((y == mlx->map_height - 1 && x == mlx->map_width - 1) || y == 1)
		add_to_window(mlx, mlx->grass, x, y);
	else if (y == 0)
		add_to_window(mlx, mlx->wall, x, y);
	else if (is_in(mlx->map[y - 1][x], "0CPE") == 1)
		add_to_window(mlx, mlx->grass, x, y);
	else
		add_to_window(mlx, mlx->dirt, x, y);
}

static void	set_map_sprite(t_mlx *mlx, int y, int x)
{
	if (mlx->map[y][x] == '1')
		check_wall(mlx, x, y);
	if (mlx->map[y][x] == '0')
		add_to_window(mlx, mlx->back, x, y);
	if (mlx->map[y][x] == 'C')
	{
		add_to_window(mlx, mlx->back, x, y);
		add_to_window(mlx, mlx->coin_sprite, x, y);
	}
	if (mlx->map[y][x] == 'P')
		add_to_window(mlx, mlx->back, x, y);
	if (mlx->map[y][x] == 'E')
	{
		add_to_window(mlx, mlx->back, x, y);
		add_to_window(mlx, mlx->portal_sprite, x, y);
	}
}

void	set_map(t_mlx *mlx)
{
	int	x;
	int	y;

	y = mlx->map_height - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < mlx->map_width)
		{
			set_map_sprite(mlx, y, x);
			x++;
		}
		y--;
	}
}
