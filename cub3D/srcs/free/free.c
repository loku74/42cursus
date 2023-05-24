/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tibernot <tibernot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:14:57 by lbourniq          #+#    #+#             */
/*   Updated: 2023/02/21 17:55:53 by tibernot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	free_walls(t_data *data)
{
	if (data->walls != NULL)
		free(data->walls);
	if (data->angles != NULL)
		free(data->angles);
}

static void	free_textures(t_data *data)
{
	int	i;

	if (data->textures != NULL)
	{
		i = 0;
		while (i < N_TEXTURES AND data->textures[i] != NULL)
		{
			if (data->textures[i]->img != NULL)
				mlx_destroy_image(data->mlx->mlx, data->textures[i]->img);
			free(data->textures[i]);
			i++;
		}
		free(data->textures);
	}
}

static void	free_colors(t_data *data)
{
	if (data->colors != NULL)
	{
		if (data->colors[FLOOR] != NULL)
			free(data->colors[FLOOR]);
		if (data->colors[CEILING] != NULL)
			free(data->colors[CEILING]);
		free(data->colors);
	}
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

void	free_all(t_data *data)
{
	free_textures(data);
	free_colors(data);
	free_walls(data);
	if (data->head != NULL)
		clear_dict(data->head);
	if (data->map != NULL)
		free_split(data->map);
	destroy_all_images(data);
	destroy_mlx(data->mlx);
}
