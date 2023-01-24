/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:10:37 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:31:30 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_put_hexa(unsigned long num, int *size)
{
	if (num >= 16)
	{
		ft_put_hexa(num / 16, size);
		ft_put_hexa(num % 16, size);
	}
	else if (num < 10)
	{
		*size += 1;
		ft_putchar_fd(num + '0', 1);
	}
	else if (num > 9 && num < 16)
	{
		*size += 1;
		ft_putchar_fd(num + 'a' - 10, 1);
	}
}

int	ft_treat_ptr(void *ptr)
{
	unsigned long	res;
	int				size;

	size = 2;
	if (!ptr)
	{
		ft_putstr_fd("0x0", 1);
		return (size + 1);
	}
	res = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	ft_put_hexa(res, &size);
	return (size);
}
