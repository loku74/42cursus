/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:33:22 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/25 18:00:54 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*ft_strrev(char *str, int sign)
{
	unsigned int	i;
	unsigned int	k;
	char			temp;

	if (!str[0])
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	i = 0;
	if (sign)
		i++;
	k = ft_strlen(str) - 1;
	while (i < (ft_strlen(str) - 1) / 2 + 1)
	{
		temp = str[i];
		str[i++] = str[k];
		str[k--] = temp;
	}
	return (str);
}

static int	int_length(long n)
{
	int	result;

	result = 1;
	if (n < 0)
	{
		n *= -1;
		result++;
	}
	while (n / 10)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;
	int		sign;
	long	k;

	k = n;
	sign = 0;
	if (k < 0)
	{
		sign = 1;
		k *= -1;
	}
	result = (char *)malloc(sizeof(char) * (int_length(k) + 1 + sign));
	if (!result)
		return (NULL);
	if (sign)
		result[0] = '-';
	i = sign;
	while (k > 0)
	{
		result[i++] = (k % 10) + 48;
		k /= 10;
	}
	result[i] = '\0';
	return (ft_strrev(result, sign));
}
