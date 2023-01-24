/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:32:16 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/20 10:01:46 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	format_map(t_mlx *mlx)
{
	char	*line;
	char	*map;
	char	*temp;

	map = NULL;
	line = get_next_line(mlx->map_fd);
	while (line)
	{
		temp = ft_strdup(map);
		if (map != NULL)
			free(map);
		map = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(mlx->map_fd);
	}
	mlx->map = ft_split(map, '\n');
	mlx->map_c = ft_split(map, '\n');
	if (map != NULL)
		free(map);
	close(mlx->map_fd);
}

void	check_map(t_mlx *mlx)
{
	format_map(mlx);
	if (mlx->map == NULL)
		errexit(mlx, "The map must not be empty");
	check_rectangular_form(mlx);
	check_map_surroundings(mlx);
	check_map_format(mlx);
}
