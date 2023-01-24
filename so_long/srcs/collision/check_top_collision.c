/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_top_collision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:05:02 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 18:37:17 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_top_collision(t_mlx *mlx)
{
	int	x;
	int	y;

	x = mlx->sprite_x;
	y = mlx->sprite_y + 10;
	x += 50;
	if (mlx->map[y / mlx->pixel][(x + 19) / mlx->pixel] == '1')
		return (1);
	if (mlx->map[y / mlx->pixel][(x - 20) / mlx->pixel] == '1')
		return (1);
	return (0);
}
