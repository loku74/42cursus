/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
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
	while (num[i])
	{
		if (num[i] != '0')
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
	if (num_int < 0 || num_int > 255)
		return (ERROR);
	return (SUCCESS);
}
