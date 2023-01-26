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

static void	free_split(char **str_split)
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

static t_exit	parse_map_identifier(t_data *data, char *line, char **ids)
{
	char	**line_split;
	int		i;

	i = 0;
	while (ids[i])
	{
		while (*line == ' ')
			line++;
		if (ft_strncmp(line, ids[i], ft_strlen(ids[i])) == 0)
		{
			line_split = ft_split(line, ' ');
			if (len_split(line_split) != 2)
				return (free_split(line_split), ERROR);
			else if (get_value(data->head, line_split[0]) != NULL)
				return (ERROR);
			else if (add_dict(data->head, line_split[0], line_split[1]))
				return (free_split(line_split), ERROR);
			return (free_split(line_split), SUCCESS);
		}
		i++;
	}
	return (ERROR);
}

t_exit	get_identifiers(t_data *data)
{
	char		*line;
	static char	*identifiers[7] = {"NO", "SO", "WE", "EA", "F", "C", NULL};

	line = get_next_line(data->map_fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 1))
		{
			if (parse_map_identifier(data, line, identifiers))
			{
				print_error_message();
				ft_putstr_color_fd("Couldn't parse map identifiers", \
				YELLOW, STDERR_FILENO, TRUE);
				clear_dict(data->head);
				return (free(line), ERROR);
			}
		}
		free(line);
		if (len_dict(data->head) != 6)
			line = get_next_line(data->map_fd);
		else
			line = NULL;
	}
	free(line);
	return (SUCCESS);
}
