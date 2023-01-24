/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:04:36 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/30 18:33:36 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_llist **node_a, t_llist **node_b)
{
	int	*tab;

	tab = NULL;
	if (ft_is_sorted(*node_a) == 0)
	{
		if (ft_llstsize(*node_a) < 50)
			ft_basic_sort(node_a, node_b);
		else
		{
			tab = ft_sort(*node_a);
			ft_get_index_base2(node_a, tab, ft_llstsize(*node_a));
			free(tab);
			ft_radix_sort(node_a, node_b);
		}
	}
	ft_free_all(node_a, NULL);
}

int	main(int argc, char **argv)
{
	t_llist	*node_a;
	t_llist	*node_b;

	node_a = NULL;
	node_b = NULL;
	if (argc < 2)
		return (0);
	node_a = ft_create_list_a(argc, argv);
	if (node_a == NULL)
	{
		if (argv[1][0])
			ft_putstr_fd("Error\n", 2);
		return (0);
	}
	push_swap(&node_a, &node_b);
	return (0);
}
