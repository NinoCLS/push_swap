/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:31:50 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/15 17:30:25 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// push a - take the first element at the top of b and put it at the top of a
// Do nothing if b is empty
void	push_a(t_tabs *tabs)
{
	if (tabs->stack_b->size == 0)
		return ;
	tabs->stack_a->size++;
	tabs->stack_a->array[tabs->stack_a->size - 1] = tabs->stack_b->array[tabs->stack_b->size - 1];
	tabs->stack_b->size--;
}

// push b - take the first element at the top of a and put it at the top of b
// Do nothing if a is empty
void	push_b(t_tabs *tabs)
{
	if (tabs->stack_a->size == 0)
		return ;
	tabs->stack_b->size++;
	tabs->stack_b->array[tabs->stack_b->size - 1] = tabs->stack_a->array[tabs->stack_a->size - 1];
	tabs->stack_a->size--;
}