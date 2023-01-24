/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:07:50 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:31:29 by lbourniq         ###   ########.fr       */
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
