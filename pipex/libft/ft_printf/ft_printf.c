/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:36:57 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 17:31:32 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_func(char c, va_list *args)
{
	if (c == 'c')
		return (ft_treat_char(va_arg(*args, int)));
	else if (c == 's')
		return (ft_treat_string(va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_treat_ptr(va_arg(*args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_treat_int(va_arg(*args, int)));
	else if (c == 'u')
		return (ft_treat_uint(va_arg(*args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_treat_hexa(va_arg(*args, unsigned int), c));
	if (c)
	{
		ft_putchar_fd(c, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		output_length;
	int		i;

	va_start(args, input);
	i = -1;
	output_length = 0;
	if (write(1, 0, 0) != 0)
		return (va_end(args), -1);
	if (!ft_strlen(input))
		return (va_end(args), 0);
	while (++i < (int)ft_strlen(input))
	{
		if (input[i] == '%')
			output_length += ft_func(input[++i], &args);
		else
		{
			ft_putchar_fd(input[i], 1);
			output_length++;
		}
	}
	return (va_end(args), output_length);
}
