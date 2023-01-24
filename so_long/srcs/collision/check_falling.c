/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_falling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:40:05 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/19 15:53:56 by lbourniq         ###   ########.fr       */
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

void	check_falling(t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->sprite_x;
	y = mlx->sprite_y;
	x += 50;
	if (is_in(mlx->map[y / 100][x / 100], "0PEC"))
	{
		mlx->falling = 1;
		mlx->idle = 0;
		if (y % 100 == 25 && mlx->map[y / 100 + 1][(x - 20) / 100] == '1')
		{
			mlx->falling = 0;
			if (mlx->run_l == 0 && mlx->run_r == 0)
				mlx->idle = 1;
		}
		if (y % 100 == 25 && mlx->map[y / 100 + 1][(x + 19) / 100] == '1')
		{
			mlx->falling = 0;
			if (mlx->run_l == 0 && mlx->run_r == 0)
				mlx->idle = 1;
		}
	}
}
