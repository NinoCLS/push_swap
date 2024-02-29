/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:20:23 by nino              #+#    #+#             */
/*   Updated: 2024/02/29 18:35:48 by nino             ###   ########.fr       */
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

static int	find_min(t_node *lst)
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