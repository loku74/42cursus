/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llst_addfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:27:07 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/26 16:49:12 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_llst_addfront(t_llist **lst, t_llist *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
