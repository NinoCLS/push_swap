/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:59:07 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/11 15:40:48 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_max(t_node *lst)
{
	int		max;
	t_node	*tmp;

	tmp = lst;
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

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

static void	radix_sort(t_node **a, t_node **b, int size)
{
	int	i;
	int	j;

	i = 0;
	while (!is_sorted(a))
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*a)->content >> i) & 1) == 1)
				rotate(a, "ra\n");
			else
				push(b, a, "pb\n");
		}
		while (*b)
			push(a, b, "pa\n");
		i++;
	}
}

void	sort(t_node **a, t_node **b, int size)
{
	if (is_sorted(a))
		return ;
	else if (size == 2 && !is_sorted(a))
		rotate(a, "sa\n");
	else if (size == 3 && !is_sorted(a))
		sort_three(a);
	else if (size == 4 && !is_sorted(a))
		sort_four(a, b);
	else if (size == 5 && !is_sorted(a))
		sort_five(a, b);
	else
		radix_sort(a, b, size);
}
