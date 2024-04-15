/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:39:54 by nclassea          #+#    #+#             */
/*   Updated: 2024/04/15 15:17:27 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_min(t_node *lst)
{
	int		min;
	t_node	*tmp;

	tmp = lst;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

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
	while (!is_sorted(a))
	{
		if ((*a)->content == find_max(*a) || (*a)->content == find_min(*a))
			rotate(a, "ra\n");
		else
			push(b, a, "pb\n");
	}
	while (*b)
		push(a, b, "pa\n");
}
