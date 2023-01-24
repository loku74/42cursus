/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 16:33:59 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/29 17:48:47 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_length(t_llist *node)
{
	int	length;

	length = 0;
	while (node)
	{
		if (length < (int)ft_strlen(node->index))
			length = (int)ft_strlen(node->index);
		node = node->next;
	}
	return (length);
}

void	ft_radix_sort(t_llist **node_a, t_llist **node_b)
{
	int	i;
	int	size;
	int	j;

	i = -1;
	while (++i < get_max_length(*node_a))
	{
		size = ft_llstsize(*node_a);
		j = -1;
		while (++j < size)
		{
			if (ft_is_sorted(*node_a))
				break ;
			if ((int)ft_strlen((*node_a)->index) < i + 1
				|| (*node_a)->index[i] == '0')
				ft_push_ft(node_a, node_b, 'b');
			else
				ft_shiftup(node_a, 'a');
		}
		while (*node_b)
			ft_push_ft(node_b, node_a, 'a');
	}
}
