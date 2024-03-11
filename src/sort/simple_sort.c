/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:39:54 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/11 15:53:35 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_node **lst)
{
	t_node	*current;
	t_node	*last;

	current = *lst;
	last = lst_last(*lst);
	sort_three_helper(current, last, lst);
}

void	sort_four(t_node **a, t_node **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->content != min)
		rotate(a, "ra\n");
	push(b, a, "pb\n");
	sort_three(a);
	push(a, b, "pa\n");
}

void	sort_five(t_node **a, t_node **b)
{
	int	min;

	min = find_min(*a);
	while ((*a)->content != min)
		rotate(a, "ra\n");
	push(b, a, "pb\n");
	sort_four(a, b);
	push(a, b, "pa\n");
}
