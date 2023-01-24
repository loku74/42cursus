/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:27:32 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/26 16:15:12 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_llst_addback(t_llist **head, t_llist *new)
{
	t_llist	*node;

	if (head == NULL || new == NULL || *head == new)
		return ;
	node = *head;
	while (node->next)
		node = node->next;
	node->next = new;
}
