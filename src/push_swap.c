/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/11 14:44:02 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

t_node	*create_stack(char **av, int ac)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	i = ac - 1;
	while (i >= 0)
	{
		add_front(&stack_a, new_node(ft_atoi(av[i])));
		i--;
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (ac == 1)
		return (0);
	av++;
	check_args(av);
	stack_b = NULL;
	stack_a = create_stack(av, ac - 1);
	normalize(&stack_a);
	sort(&stack_a, &stack_b, ac - 1);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
