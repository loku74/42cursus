/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:32:31 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/19 18:24:09 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_window(t_mlx *mlx)
{
	int	step_x;
	int	step_s;

	step_x = mlx->map_width * mlx->pixel / 2 + 25;
	step_s = mlx->map_width * mlx->pixel / 2 - 35;
	if (mlx->win != NULL)
		mlx_clear_window(mlx->mlx, mlx->win);
	set_map(mlx);
	mlx_put_image_to_window(
		mlx->mlx,
		mlx->win,
		mlx->sprite,
		mlx->sprite_x,
		mlx->sprite_y
		);
	mlx->strsteps = ft_itoa(mlx->steps / 5);
	mlx_string_put(mlx->mlx, mlx->win, step_s, 50, 0x000000, "step(s): ");
	mlx_string_put(mlx->mlx, mlx->win, step_x, 50, 0x000000, mlx->strsteps);
	free(mlx->strsteps);
}
