/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:28:27 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/25 15:28:28 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static t_exit	parse_map_identifier(t_data *data, char *line, char **ids)
{
	char	**line_split;
	int		i;

	i = 0;
	while (*line == ' ')
		line++;
	while (i < N_IDENTIFIERS)
	{
		if (ft_strncmp(line, ids[i], ft_strlen(ids[i])) == 0)
		{
			line_split = ft_split(line, " \n");
			if (line_split == NULL)
				return (r_error(MALLOC_ERROR));
			if (len_split(line_split) != ELEMENT_COUNT)
				return (free_split(line_split), r_error(PARSING_ERROR));
			else if (get_value(data->head, line_split[0]) != NULL)
				return (free_split(line_split), r_error(PARSING_ERROR));
			else if (add_dict(data->head, line_split[0], line_split[1]))
				return (free_split(line_split), r_error(MALLOC_ERROR));
			free_split(line_split);
			return (SUCCESS);
		}
		i++;
	}
	return (r_error(PARSING_ERROR));
}

t_exit	get_identifiers(t_data *data)
{
	char		*line;
	static char	*ids[N_IDENTIFIERS] = {"NO ", "SO ", "WE ", "EA ", "F ", "C "};

	line = get_next_line(data->map_fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 1))
		{
			if (parse_map_identifier(data, line, ids))
			{
				free(line);
				return (ERROR);
			}
		}
		free(line);
		if (len_dict(data->head) != N_IDENTIFIERS)
			line = get_next_line(data->map_fd);
		else
			line = NULL;
	}
	free(line);
	return (SUCCESS);
}
