/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:02:14 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:31:31 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_put_hexa(unsigned int num, int *size, int format)
{
	if (num >= 16)
	{
		ft_put_hexa(num / 16, size, format);
		ft_put_hexa(num % 16, size, format);
	}
	else if (num < 10)
	{
		*size += 1;
		ft_putchar_fd(num + '0', 1);
	}
	else if (num > 9 && num < 16)
	{
		*size += 1;
		if (format == 'x')
			ft_putchar_fd(num + 'a' - 10, 1);
		else
			ft_putchar_fd(num + 'A' - 10, 1);
	}
}

int	ft_treat_hexa(unsigned int num, int format)
{
	int	len_num;

	len_num = 0;
	ft_put_hexa(num, &len_num, format);
	return (len_num);
}
