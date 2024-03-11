/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:20:23 by nino              #+#    #+#             */
/*   Updated: 2024/03/11 15:40:10 by nclassea         ###   ########.fr       */
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

void	sort_three_helper(t_node *current, t_node *last, t_node **lst)
{
	if (current->content > current->next->content
		&& last->content > current->content)
		swap(*lst, "sa\n");
	else if (current->content > current->next->content
		&& current->content > last->content
		&& current->next->content < last->content)
		rotate(lst, "ra\n");
	else if (last->content < current->content
		&& last->content < current->next->content
		&& current->content < current->next->content)
		reverse_rotate(lst, "rra\n");
	else if (current->content > current->next->content
		&& current->content > last->content
		&& current->next->content > last->content)
		sort_three_complex_case(lst);
	else if (current->content < last->content
		&& last->content < current->next->content)
		sort_three_reverse_case(lst);
}

void	sort_three_complex_case(t_node **lst)
{
	rotate(lst, "ra\n");
	swap(*lst, "sa\n");
}

void	sort_three_reverse_case(t_node **lst)
{
	reverse_rotate(lst, "rra\n");
	swap(*lst, "sa\n");
}
