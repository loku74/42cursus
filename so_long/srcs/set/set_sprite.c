/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:49:57 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/20 09:31:49 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_sprite(t_mlx *mlx)
{
	mlx->sprite_h = 100;
	mlx->sprite_w = 75;
	mlx->idle = 1;
	mlx->run_r = 0;
	mlx->run_l = 0;
	mlx->left = 0;
	mlx->jumping = 0;
	mlx->jump_frame = 0;
	mlx->curr_jumping = 0;
	mlx->falling = 0;
	mlx->sprite_x *= 100;
	mlx->sprite_y *= 100;
	mlx->collectibles_collected = 0;
	update_sprite(mlx, mlx->idle_r[0]);
}
