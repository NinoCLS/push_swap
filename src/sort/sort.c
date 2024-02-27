/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:59:07 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/27 19:18:39 by nclassea         ###   ########.fr       */
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


// sa (swap a): If there are 2 numbers, swap the first 2 elements at the top of the stack a.
// sb (swap b): If there are 2 numbers, swap the first 2 elements at the top of the stack b.
// ss: sa and sb at the same time.
// pa (push a): Take the first element at the top of b and put it at the top of a.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
// rr: ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
// rrr: rra and rrb at the same time.


// trier 3 elements avec un MAXIMUM de 2 instructions
static void sort_three(t_node **a)
{
	// si 1 3 2 -> sa -> ra -> 1 2 3
	if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
	{
		swap(*a, "sa\n");
		rotate(a, "ra\n");
	}

	// si 3 2 1 ->rra -> sa -> 1 2 3 
	else if ((*a)->content > (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
	{
		rotate(a, "rra\n");
		swap(*a, "sa\n");
	}


	// si 3 1 2 -> rra -> sa -> ra -> 1 2 3
	else if ((*a)->content > (*a)->next->content && (*a)->next->content < (*a)->next->next->content)
	{
		reverse_rotate(a, "rra\n");
	}
	

	// // si 2 1 3 -> ra -> sa -> rra -> 1 2 3
	// else if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
	// {
	// 	rotate(a, "ra\n");
	// 	rotate(a, "sa\n");
	// 	reverse_rotate(a, "rra\n");
	// }
	// // si 2 3 1 -> rra -> sa -> ra -> 1 2 3
	// else if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
	// {
	// 	reverse_rotate(a, "rra\n");
	// 	rotate(a, "sa\n");
	// 	rotate(a, "ra\n");
	// }
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
