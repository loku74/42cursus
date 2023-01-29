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

static t_exit	set_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (r_error(MLX_INIT_FAIL));
	data->mlx_win = mlx_new_window(data->mlx, WINDOW_X, WINDOW_Y, WINDOW_NAME);
	if (data->mlx_win == NULL)
		return (r_error(MLX_WIN_FAIL));
	data->img = mlx_new_image(data->mlx, WINDOW_X, WINDOW_Y);
	if (data->img == NULL)
		return (r_error(MLX_IMG_FAIL));
	data->img_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	if (data->img_addr == NULL)
		return (r_error(MLX_GETAD_FAIL));
}

int	main(int argc, char **argv)
{
	t_data	data;

	for (int i = 0; i < WINDOW_X; i++)
	{
		for (int j = 0; j < WINDOW_Y; j++)
			my_pixel_put(&data, i, j, 0x00424242);
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
	printf("mlx pointer: %p\n", data.mlx);
	printf("mlx window pointer: %p\n", data.mlx_win);
	if (parsing(&data, argv, argc))
		return (ERROR);
	if (set_mlx(&data))
		return (ERROR);
	for (int i = 0; i < WINDOW_X; i++)
	{
		for (int j = 0; j < WINDOW_Y; j++)
			my_pixel_put(&data, i, j, 0x00424242);
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
	printf("mlx pointer: %p\n", data.mlx);
	printf("mlx window pointer: %p\n", data.mlx_win);
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
