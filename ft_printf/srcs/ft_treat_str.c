/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:07:50 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/13 15:10:09 by lbourniq         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_treat_string(char *str)
{
	if (str)
	{
		ft_putstr_fd(str, 1);
		return ((int)ft_strlen(str));
	}
	ft_putstr_fd("(null)", 1);
	return (6);
}
