/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbourniq <lbourniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:01:15 by lbourniq          #+#    #+#             */
/*   Updated: 2022/11/30 17:46:14 by lbourniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/includes/libft.h"

typedef struct s_llist
{
	int				num;
	char			*index;
	struct s_llist	*next;
}t_llist;

int		ft_is_sorted(t_llist *head);
int		ft_llstsize(t_llist *head);

int		*ft_sort(t_llist *head);

t_llist	*ft_create_list_a(int argc, char **argv);
t_llist	*ft_create_new_llist(int num);

void	ft_basic_sort(t_llist **node_a, t_llist **node_b);
void	ft_free_all(t_llist **head, char **tab);
void	free_tab(char **tab);
void	ft_llst_addback(t_llist **head, t_llist *new);
void	ft_llst_addfront(t_llist **lst, t_llist *new);
void	ft_get_index_base2(t_llist **node_a, int *tab, int length);
void	ft_push_ft(t_llist **head1, t_llist **head2, char c);
void	ft_radix_sort(t_llist **node_a, t_llist **node_b);
void	ft_shiftdown(t_llist **head, char c);
void	ft_shiftup(t_llist **head, char c);
void	ft_swap_f2(t_llist *head, char c);

#endif
