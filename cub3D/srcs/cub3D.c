/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:55:44 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/24 09:55:45 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	key_pressed(int key, t_player *player)
{
	if (key == W)
		player->forward = TRUE;
	else if (key == A)
		player->left = TRUE;
	else if (key == S)
		player->back = TRUE;
	else if (key == D)
		player->right = TRUE;
	else if (key == LEFT)
		player->move_fov_left = TRUE;
	else if (key == RIGHT)
		player->move_fov_right = TRUE;
	return (0);
}

static int	key_released(int key, t_player *player)
{
	if (key == W)
		player->forward = FALSE;
	else if (key == A)
		player->left = FALSE;
	else if (key == S)
		player->back = FALSE;
	else if (key == D)
		player->right = FALSE;
	else if (key == LEFT)
		player->move_fov_left = FALSE;
	else if (key == RIGHT)
		player->move_fov_right = FALSE;
	return (0);
}

static int	render_next_frame(t_data *data)
{
	update_player(&data->player);
	draw_2d(data, data->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;

	data.mlx = &mlx;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (r_error(MLX_INIT_FAIL));
	if (parsing(&data, argv, argc))
		return (ERROR);
	if (set_mlx(&data, &mlx))
		return (ERROR);
	set_player(&data, &data.player);
	mlx_hook(mlx.win, 2, 1L << 0, key_pressed, &data.player);
	mlx_hook(mlx.win, 3, 1L << 1, key_released, &data.player);
	mlx_loop_hook(mlx.mlx, render_next_frame, &data);
	mlx_loop(mlx.mlx);
	printf("mlx pointer: %p\n", mlx.mlx);
	printf("mlx window pointer: %p\n", mlx.win);
	printf("ceiling R G B color: %d, %d, %d\n", data.colors[CEILING][R], data.colors[CEILING][G], data.colors[CEILING][B]);
	printf("floor R G B color: %d, %d, %d\n", data.colors[FLOOR][R], data.colors[FLOOR][G], data.colors[FLOOR][B]);
	printf("Address of EA mlx image: %p\n", data.textures[EA]);
	printf("Address of WE mlx image: %p\n", data.textures[WE]);
	printf("Address of SO mlx image: %p\n", data.textures[SO]);
	printf("Address of NO mlx image: %p\n", data.textures[NO]);
	free_textures(&data, N_TEXTURES, TRUE);
	free_colors(&data);
	free_split(data.map);
	return (SUCCESS);
}
