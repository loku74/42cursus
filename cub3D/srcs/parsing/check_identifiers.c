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

t_exit	check_identifiers(t_data *data)
{
	if (len_dict(data->head) != 6)
	{
		clear_dict(data->head);
		print_error_message();
		ft_putstr_color_fd("Couldn't parse map identifiers", \
		YELLOW, STDERR_FILENO, TRUE);
		return (ERROR);
	}
	return (SUCCESS);
}
