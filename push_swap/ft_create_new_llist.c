/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_llist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:40:39 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/28 10:10:08 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*ft_create_new_llist(int num)
{
	t_llist	*node;

	node = malloc(sizeof(t_llist));
	if (node == NULL)
		return (NULL);
	node->num = num;
	node->next = NULL;
	node->index = NULL;
	return (node);
}
