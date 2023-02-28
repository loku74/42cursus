/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:21:11 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/26 10:21:12 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static char	*add(char *map, char *line)
{
	char	*map_ret;

	map_ret = ft_strjoin(map, line);
	if (map != NULL)
		free(map);
	free(line);
	return (map_ret);
}

t_exit	get_map(t_data *data)
{
	char	*line;
	char	*map;

	map = NULL;
	line = get_next_line(data->map_fd);
	while (ft_strncmp(line, "\n", ft_strlen(line)) == SUCCESS)
	{
		free(line);
		line = get_next_line(data->map_fd);
	}
	if (line == NULL)
		return (free(line), r_error(MAP_MISSING));
	while (line AND ft_strncmp(line, "\n", ft_strlen(line)) != SUCCESS)
	{
		map = add(map, line);
		if (map == NULL)
			return (r_error(MALLOC_ERROR));
		line = get_next_line(data->map_fd);
	}
	if (line != NULL)
		return (free(line), free(map), r_error(INVALID_MAP));
	data->map = ft_split(map, "\n");
	free(map);
	return (SUCCESS);
}
