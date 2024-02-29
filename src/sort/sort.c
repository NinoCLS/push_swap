/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:59:07 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/29 20:08:44 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	radix_sort(t_node **a, t_node **b, int size)
{
	int	i;
	int	j;
	
	i = 0;
	while(!is_sorted(a))
	{
		j = 0;
		while (j++ < size)
		{
			if((((*a)->content >> i) & 1) == 1)
				rotate(a, "ra\n");
			else
				push(b, a, "pb\n");
		}
		while(*b)
			push(a, b, "pa\n");
		i++;
	}
}

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


void	sort(t_node **a, t_node **b, int size)
{
	(void)b;
	if (is_sorted(a))
	{
		ft_printf("sorted\n");
		return ;
	}
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
