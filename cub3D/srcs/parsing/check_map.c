/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:01:14 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/26 10:01:15 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_exit	check_map_chars(t_data *data)
{
	int	i;
	int	j;
	int	spawn;

	j = 0;
	spawn = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (is_in(data->map[j][i], VALID_CHARS) == FALSE)
				return (r_error(INVALID_CHARS));
			else if (is_in(data->map[j][i], PLAYER_SPAWN))
				spawn++;
			i++;
		}
		j++;
	}
	if (spawn != 1)
		return (r_error(SPAWN_COUNT_ER));
	return (SUCCESS);
}

static t_exit	check_surrounding(t_data *data, int i, int j)
{
	if (j == 0 OR j == len_split(data->map) - 1)
		return (ERROR);
	else if (i == 0 OR i == (int)ft_strlen(data->map[j]) - 1)
		return (ERROR);
	else if ((int)ft_strlen(data->map[j - 1]) <= i)
		return (ERROR);
	else if ((int)ft_strlen(data->map[j + 1]) <= i)
		return (ERROR);
	else if (data->map[j + 1][i] == ' ' OR data->map[j - 1][i] == ' ')
		return (ERROR);
	else if (data->map[j][i + 1] == ' ' OR data->map[j][i - 1] == ' ')
		return (ERROR);
	return (SUCCESS);
}

static t_exit	check_map_format(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (is_in(data->map[j][i], FREE_SPACES))
			{
				if (check_surrounding(data, i, j))
					return (r_error(MAP_SURR_ER));
			}
			i++;
		}
		j++;
	}
	return (SUCCESS);
}

t_exit	check_map(t_data *data)
{
	if (data->map == NULL)
		return (r_error(MALLOC_ERROR));
	if (check_map_chars(data))
		return (ERROR);
	if (check_map_format(data))
		return (ERROR);
	return (SUCCESS);
}
