/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:31:37 by lbourniq          #+#    #+#             */
/*   Updated: 2023/01/27 10:31:38 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	num_len(char *num)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (num[i] == '0')
		i++;
	while (num[i])
	{
		k++;
		i++;
	}
	return (k);
}

t_exit	check_num(char *num)
{
	int	i;
	int	num_int;

	i = 0;
	if (num_len(num) > 3)
		return (ERROR);
	while (num[i])
	{
		if (ft_isdigit(num[i]) == FALSE)
			return (ERROR);
		i++;
	}
	num_int = ft_atoi(num);
	if (num_int < 0 OR num_int > 255)
		return (ERROR);
	return (SUCCESS);
}

static int	count_comma(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

t_exit	check_rgb(char *rgb)
{
	int	i;
	int	len_rgb;

	i = 0;
	len_rgb = (int)ft_strlen(rgb);
	if (ft_isdigit(rgb[i]) == FALSE OR ft_isdigit(rgb[len_rgb - 1]) == FALSE)
		return (r_error(RGB_ERROR));
	if (count_comma(rgb) != 2)
		return (r_error(RGB_ERROR));
	return (SUCCESS);
}

t_exit	check_all(t_data *data, char **argv, int argc)
{
	if (set_walls(data))
		return (ERROR);
	if (parsing(data, argv, argc))
	{
		free_all(data);
		return (ERROR);
	}
	if (set_mlx(data, data->mlx))
	{
		free_all(data);
		return (ERROR);
	}
	if (init_imgs(data))
	{
		free_all(data);
		return (ERROR);
	}
	return (SUCCESS);
}
