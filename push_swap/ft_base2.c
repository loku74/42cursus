/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:28:52 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/29 15:52:35 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_len_num(int num)
{
	int		len;

	len = 0;
	while (num != 0)
	{
		num /= 2;
		len++;
	}
	return (len);
}

static char	*ft_itoa_base2(int num)
{
	char	*res;
	int		len_num;
	int		i;

	len_num = ft_len_num(num);
	if (num == 0)
	{
		res = (char *)malloc(sizeof(char) * 2);
		if (!res)
			return (NULL);
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * (len_num + 1));
	if (!res)
		return (NULL);
	res[len_num] = '\0';
	i = 0;
	while (i < len_num)
	{
		res[i++] = "01"[num % 2];
		num /= 2;
	}
	return (res);
}

void	ft_get_index_base2(t_llist **node_a, int *tab, int length)
{
	t_llist	*node;
	int		i;
	int		num;

	i = 0;
	while (i < length)
	{
		node = *node_a;
		num = tab[i];
		while (tab[i] != node->num)
			node = node->next;
		node->index = ft_itoa_base2(i);
		i++;
	}
}
