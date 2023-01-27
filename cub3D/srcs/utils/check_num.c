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

t_exit	check_num(char *num)
{
	int	i;
	int	num_int;

	i = 0;
	if (ft_strlen(num) > 3)
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
