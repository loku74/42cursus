/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:48:07 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/29 17:51:37 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_llist *head)
{
	while (head)
	{
		if (head->next)
		{
			if (head->num > head->next->num)
				return (0);
		}
		head = head->next;
	}
	return (1);
}
