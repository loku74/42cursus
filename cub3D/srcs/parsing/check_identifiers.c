/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_identifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:22:30 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/26 10:22:31 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_exit	treat_identifiers(t_data *data)
{
	static char	*identifiers[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int			i;
	char		*value;

	i = 0;
	while (identifiers[i] != NULL)
	{
		value = get_value(data->head, identifiers[i]);
		if (i == 0)
		{
			data->textures.north = mlx_xpm_file_to_image(data->mlx, \
			value, &data->img_width, &data->img_height);
			if (data->textures.north == NULL)
				return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

t_exit	check_identifiers(t_data *data)
{
	if (len_dict(data->head) != N_IDENTIFIERS || treat_identifiers(data))
	{
		clear_dict(data->head);
		print_error_message();
		ft_putstr_color_fd("Couldn't parse map identifiers", \
		YELLOW, STDERR_FILENO, TRUE);
		return (ERROR);
	}
	return (SUCCESS);
}
