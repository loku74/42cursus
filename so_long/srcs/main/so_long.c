/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:28:52 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/20 09:39:47 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	close_game(t_mlx *mlx)
{
	errexit(mlx, NULL);
	return (0);
}

static int	key_pressed(int key, t_mlx *mlx)
{
	if (key == 2)
	{
		mlx->left = 0;
		mlx->idle = 0;
		mlx->run_r = 1;
	}
	else if (key == 0)
	{
		mlx->left = 1;
		mlx->idle = 0;
		mlx->run_l = 1;
	}
	else if (key == 13 || key == 49)
	{
		mlx->jumping = 1;
		mlx->curr_jumping = 1;
		mlx->idle = 0;
	}
	else if (key == 1)
		mlx->jumping = 0;
	else if (key == 53)
		close_game(mlx);
	return (0);
}

static int	key_released(int key, t_mlx *mlx)
{
	if (key == 2)
	{
		mlx->run_r = 0;
		if (mlx->run_l == 0 && mlx->jumping == 0 && mlx->falling == 0)
			mlx->idle = 1;
		else if (mlx->run_l == 1)
			mlx->left = 1;
	}
	else if (key == 0)
	{
		mlx->run_l = 0;
		if (mlx->run_r == 0 && mlx->jumping == 0 && mlx->falling == 0)
			mlx->idle = 1;
		else if (mlx->run_r == 1)
			mlx->left = 0;
	}
	else if (key == 13 || key == 49)
		mlx->curr_jumping = 0;
	return (0);
}

static int	render_next_frame(t_mlx *mlx)
{
	check_falling(mlx);
	check_coin_collision(mlx);
	check_portal_collision(mlx);
	if (mlx->jumping == 1)
		jump(mlx);
	else
		mlx->jump_frame = 0;
	if (mlx->falling == 1)
		fall(mlx);
	if (mlx->idle == 1)
		idle(mlx);
	if (mlx->run_l || mlx->run_r)
		run(mlx);
	coin_animation(mlx);
	portal_animation(mlx);
	if (mlx->steps == INT32_MAX)
		mlx->steps = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	set_init(&mlx);
	check_input_error(argc, argv, &mlx);
	parsing(&mlx);
	set_all(&mlx);
	mlx_hook(mlx.win, 2, 1L << 0, key_pressed, &mlx);
	mlx_hook(mlx.win, 3, 1L << 1, key_released, &mlx);
	mlx_hook(mlx.win, 17, 1L << 2, close_game, &mlx);
	mlx_loop_hook(mlx.mlx, render_next_frame, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
