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
	free_textures(&data, N_TEXTURES, TRUE);
	free_colors(&data);
	clear_dict(data.head);
	return (SUCCESS);
}
