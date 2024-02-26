/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:59:07 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/26 18:10:17 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// void	sort_small_stack(t_list **a, t_list **b, int size)
// {
	
// }

int	is_sorted(t_list **a)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (*(int *)tmp->content > *(int *)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort(t_list **a, t_list **b, int size)
{
	(void)b;
	if (size == 2 && !is_sorted(a))
		rotate(a, "sa\n");
	else if (size <= 50 && size > 2 && !is_sorted(a))
		sort_small_stack(a, b, size);
	// else if (size > 50 && !a_is_sorted(a))
	// 	sort_big_stack(a, b, size);
	// else
	// 	return ;
}
