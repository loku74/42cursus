/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:55:44 by lbourniq          #+#    #+#             */
/*   Updated: 2023/03/03 09:48:20 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	quit_game(t_data *data)
{
	free_all(data);
	exit(SUCCESS);
}

static int	key_pressed(int key, t_data *data)
{
	if (key == W)
		data->player.forward = TRUE;
	else if (key == A)
		data->player.left = TRUE;
	else if (key == S)
		data->player.back = TRUE;
	else if (key == D)
		data->player.right = TRUE;
	else if (key == LEFT)
		data->player.move_fov_left = TRUE;
	else if (key == RIGHT)
		data->player.move_fov_right = TRUE;
	else if (key == ESC)
		quit_game(data);
	return (0);
}

static int	key_released(int key, t_data *data)
{
	if (key == W)
		data->player.forward = FALSE;
	else if (key == A)
		data->player.left = FALSE;
	else if (key == S)
		data->player.back = FALSE;
	else if (key == D)
		data->player.right = FALSE;
	else if (key == LEFT)
		data->player.move_fov_left = FALSE;
	else if (key == RIGHT)
		data->player.move_fov_right = FALSE;
	return (0);
}

static int	render_next_frame(t_data *data)
{
	update_player(&data->player, data);
	raycasting(data);
	put_walls(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;

	set_all(&data, &mlx);
	data.mlx = &mlx;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (free_all(&data), r_error(MLX_INIT_FAIL));
	if (check_all(&data, argv, argc))
		return (ERROR);
	init_background(&data);
	set_player(&data, &data.player);
	mlx_hook(mlx.win, 2, 1L << 0, key_pressed, &data);
	mlx_hook(mlx.win, 3, 1L << 1, key_released, &data);
	mlx_hook(mlx.win, 17, 1L << 2, quit_game, &data);
	mlx_loop_hook(mlx.mlx, render_next_frame, &data);
	mlx_loop(mlx.mlx);
	return (SUCCESS);
}
