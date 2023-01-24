/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coin_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:09:51 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 17:21:30 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_coin_collision(t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->sprite_x + 50;
	y = mlx->sprite_y + 37;
	if (mlx->map[y / 100][x / 100] == 'C')
	{
		mlx->collectibles_collected++;
		mlx->map[y / 100][x / 100] = '0';
	}
}
