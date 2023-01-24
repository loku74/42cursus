/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:02:30 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:31:30 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putnbr(int n, int *len_num)
{
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		if (n == -2147483648)
		{
			ft_putstr_fd("2147483648", 1);
			*len_num += 10;
		}
		else
			ft_putnbr(n * -1, len_num);
		*len_num += 1;
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, len_num);
		ft_putnbr(n % 10, len_num);
	}
	else
	{
		ft_putchar_fd(n + 48, 1);
		*len_num += 1;
	}
}

int	ft_treat_int(int num)
{
	int	len_num;

	len_num = 0;
	ft_putnbr(num, &len_num);
	return (len_num);
}
