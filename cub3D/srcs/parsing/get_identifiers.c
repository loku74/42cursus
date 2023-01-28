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

void	print_dict(t_dict *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		printf("index: %d\n", i);
		printf("key: %s\n", head->key);
		printf("value: %s\n", head->value);
		head = head->next;
		i++;
	}
}

static t_exit	parse_map_identifier(t_data *data, char *line, char **ids)
{
	char	**line_split;
	int		i;

	i = 0;
	while (i < N_IDENTIFIERS)
	{
		line_split = ft_split(line, ' ');
		if (ft_strncmp(line, ids[i], ft_strlen(line_split[0])) == 0)
		{
			if (len_split(line_split) != 2)
				return (free_split(line_split), ERROR);
			else if (get_value(data->head, line_split[0]) != NULL)
				return (free_split(line_split), ERROR);
			else if (add_dict(data->head, line_split[0], line_split[1]))
				return (free_split(line_split), ERROR);
			free_split(line_split);
			return (SUCCESS);
		}
		free_split(line_split);
		i++;
	}
	return (ERROR);
}

t_exit	get_identifiers(t_data *data)
{
	char		*line;
	static char	*ids[N_IDENTIFIERS] = {"NO", "SO", "WE", "EA", "F", "C"};

	line = get_next_line(data->map_fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 1))
		{
			if (parse_map_identifier(data, line, ids))
			{
				clear_dict(data->head);
				free(line);
				return (r_error("Couldn't parse map identifiers"));
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
