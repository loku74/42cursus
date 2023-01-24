/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 09:46:28 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 18:41:22 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_all(t_mlx *mlx)
{
	mlx->pixel = 100;
	set_window(mlx);
	mlx->win = mlx_new_window(mlx->mlx, mlx->win_x, mlx->win_y, "so_long");
	set_portal(mlx);
	set_idle_right(mlx);
	set_idle_left(mlx);
	set_running_left(mlx);
	set_running_right(mlx);
	set_jumping_r(mlx);
	set_jumping_l(mlx);
	set_falling_r(mlx);
	set_falling_l(mlx);
	set_sprite(mlx);
	set_assets(mlx);
	set_map(mlx);
}
