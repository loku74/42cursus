/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:48:38 by lbourniq          #+#    #+#             */
/*   Updated: 2022/12/01 09:42:09 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_llist **head)
{
	t_llist	*node;
	int		min;

	node = *head;
	min = node->num;
	while (node)
	{
		if (node->num < min)
			min = node->num;
		node = node->next;
	}
	return (min);
}

static int	find_max(t_llist **head)
{
	t_llist	*node;
	int		max;

	node = *head;
	max = node->num;
	while (node)
	{
		if (node->num > max)
			max = node->num;
		node = node->next;
	}
	return (max);
}

static int	get_num_index(t_llist **head, int num)
{
	t_llist	*node;
	int		i;

	node = *head;
	i = 0;
	while (node)
	{
		if (node->num == num)
			return (i);
		node = node->next;
		i++;
	}
	return (i);
}

static void	ft_simple_sort(t_llist **head)
{
	if (get_num_index(head, find_max(head)) == 0)
	{
		if (get_num_index(head, find_min(head)) == 1)
			ft_shiftup(head, 'a');
	}
	else if (get_num_index(head, find_max(head)) == 1)
	{
		if (get_num_index(head, find_min(head)) == 2)
			ft_shiftdown(head, 'a');
	}
	if (ft_is_sorted(*head) == 0)
	{
		ft_swap_f2(*head, 'a');
		if (get_num_index(head, find_min(head)) == 1)
			ft_shiftup(head, 'a');
		else if (get_num_index(head, find_min(head)) == 2)
			ft_shiftdown(head, 'a');
	}
}

void	ft_basic_sort(t_llist **node_a, t_llist **node_b)
{
	int	min;

	if (ft_llstsize(*node_a) <= 3)
		ft_simple_sort(node_a);
	while (!ft_is_sorted(*node_a))
	{
		min = find_min(node_a);
		if ((*node_a)->num == min)
		{
			ft_push_ft(node_a, node_b, 'b');
			min = find_min(node_a);
		}
		if ((*node_a)->num == min)
			ft_push_ft(node_a, node_b, 'b');
		if (get_num_index(node_a, min) > ft_llstsize(*node_a) / 2)
			ft_shiftdown(node_a, 'a');
		else
			ft_shiftup(node_a, 'a');
	}
	while (*node_b)
		ft_push_ft(node_b, node_a, 'a');
}
