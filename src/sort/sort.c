/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:59:07 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/28 17:27:13 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_node **a)
{
	t_node	*tmp;

	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_three(t_node **lst)
{
	t_node	*current;
	t_node	*last;

	current = *lst;
	last = lst_last(*lst);
	if (current->content > current->next->content && last->content > current->content)
		swap(*lst, "sa\n");
	else if (current->content > current->next->content
		&& current->content > last->content && current->next->content < last->content)
		rotate(lst, "ra\n");
	else if (last->content < current->content && last->content < current->next->content
		&& current->content < current->next->content)
		reverse_rotate(lst, "rra\n");
	else if (current->content > current->next->content
		&& current->content > last->content && current->next->content > last->content)
	{
		rotate(lst, "ra\n");
		swap(*lst, "sa\n");
	}
	else if (current->content < last->content && last->content < current->next->content)
	{
		reverse_rotate(lst, "rra\n");
		swap(*lst, "sa\n");
	}
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
	// else if (size <= 50 && size > 2 && !is_sorted(a))
	// 	small_sort(a, b, size);
	
}
