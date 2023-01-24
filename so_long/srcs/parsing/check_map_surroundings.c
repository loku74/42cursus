/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_surroundings.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:25:52 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/18 17:38:20 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	get_map_width(char **map)
{
	int	i;

	i = 0;
	while (*map && map[0][i])
		i++;
	return (i);
}

static int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (*map && map[i])
		i++;
	return (i);
}

static void	check_v_walls(t_mlx *mlx, char **map, int map_width, int map_height)
{
	int	i;

	i = 0;
	while (i < map_height)
	{
		if (map[i][0] != '1' || map[i][map_width - 1] != '1')
			errexit(mlx, "The map must be surrounded by walls ('1')");
		i++;
	}
}

static void	check_h_walls(t_mlx *mlx, char **map, int map_height, int map_width)
{
	int	i;

	i = 0;
	while (i < map_width)
	{
		if (map[0][i] != '1' || map[map_height - 1][i] != '1')
			errexit(mlx, "The map must be surrounded by walls ('1')");
		i++;
	}
}

void	check_map_surroundings(t_mlx *mlx)
{
	mlx->map_width = get_map_width(mlx->map);
	mlx->map_height = get_map_height(mlx->map);
	check_v_walls(mlx, mlx->map, mlx->map_width, mlx->map_height);
	check_h_walls(mlx, mlx->map, mlx->map_height, mlx->map_width);
}
