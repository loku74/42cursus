/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:14:57 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/27 10:14:58 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	free_textures(t_data *data, int k, t_bool destroy_img)
{
	int	i;

	i = 0;
	while (i < k)
	{
		if (destroy_img == TRUE)
			mlx_destroy_image(data->mlx->mlx, data->textures[i]);
		i++;
	}
	free(data->textures);
}

void	free_colors(t_data *data)
{
	free(data->colors[FLOOR]);
	free(data->colors[CEILING]);
	free(data->colors);
}

void	free_split(char **str_split)
{
	int	i;

	i = 0;
	while (str_split[i])
	{
		free(str_split[i]);
		i++;
	}
	free(str_split[i]);
	free(str_split);
}
