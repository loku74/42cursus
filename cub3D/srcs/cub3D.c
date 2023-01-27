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

int	main(int argc, char **argv)
{
	t_data	data;

	data.mlx = mlx_init();
	printf("mlx pointer: %p\n", data.mlx);
	data.head = create_new_dict();
	if (data.head == NULL)
		return (ERROR);
	if (parsing(&data, argv, argc))
		return (ERROR);
	printf("ceiling R G B color: %d, %d, %d\n", data.colors[CEILING][R], data.colors[CEILING][G], data.colors[CEILING][B]);
	printf("floor R G B color: %d, %d, %d\n", data.colors[FLOOR][R], data.colors[FLOOR][G], data.colors[FLOOR][B]);
	printf("path to EA texture: %s\n", get_value(data.head, "EA"));
	printf("path to WE texture: %s\n", get_value(data.head, "WE"));
	printf("path to SO texture: %s\n", get_value(data.head, "SO"));
	printf("path to NO texture: %s\n", get_value(data.head, "NO"));
	printf("Address of EA mlx image: %p\n", data.textures[EA]);
	printf("Address of WE mlx image: %p\n", data.textures[WE]);
	printf("Address of SO mlx image: %p\n", data.textures[SO]);
	printf("Address of NO mlx image: %p\n", data.textures[NO]);
	free_textures(&data, N_TEXTURES, TRUE);
	free_colors(&data);
	clear_dict(data.head);
	return (SUCCESS);
}
