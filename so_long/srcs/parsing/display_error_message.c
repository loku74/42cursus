/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error_message.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:27:44 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/20 10:03:53 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

static void	destroy_assets(t_mlx *mlx)
{
	if (mlx->back != NULL)
		mlx_destroy_image(mlx->mlx, mlx->back);
	if (mlx->grass != NULL)
		mlx_destroy_image(mlx->mlx, mlx->grass);
	if (mlx->dirt != NULL)
		mlx_destroy_image(mlx->mlx, mlx->dirt);
	if (mlx->wall != NULL)
		mlx_destroy_image(mlx->mlx, mlx->wall);
}

void	errexit(t_mlx *mlx, char *error_message)
{
	destroy_assets(mlx);
	if (mlx->map != NULL)
		free_map(mlx->map);
	if (mlx->map_c != NULL)
		free_map(mlx->map_c);
	if (mlx->sprite != NULL)
		mlx_destroy_image(mlx->mlx, mlx->sprite);
	if (mlx->coin_sprite != NULL)
		mlx_destroy_image(mlx->mlx, mlx->coin_sprite);
	if (mlx->portal_sprite != NULL)
		mlx_destroy_image(mlx->mlx, mlx->portal_sprite);
	if (mlx->win != NULL)
	{
		mlx_clear_window(mlx->mlx, mlx->win);
		mlx_destroy_window(mlx->mlx, mlx->win);
	}
	if (error_message != NULL)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		ft_putendl_fd(error_message, STDERR_FILENO);
	}
	exit(0);
}
