/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:09:53 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/11 14:46:48 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_node *stack, char *instructions)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	stack->content = stack->next->content;
	stack->next->content = tmp;
	ft_putstr_fd(instructions, 1);
}

void	push(t_node **stack_one, t_node **stack_two, char *instructions)
{
	if (!(*stack_two))
		return ;
	add_front(stack_one, pop_front(stack_two));
	ft_putstr_fd(instructions, 1);
}

void	rotate(t_node **stack, char *instructions)
{
	t_node	*first;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->prev = last;
	ft_putstr_fd(instructions, 1);
}

void	reverse_rotate(t_node **stack, char *instructions)
{
	t_node	*first;
	t_node	*last;
	t_node	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = first;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	ft_putstr_fd(instructions, 1);
}
