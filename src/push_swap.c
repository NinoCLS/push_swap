/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/29 20:24:54 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// create stack 
t_node	*create_stack(char **av, int ac)
{
	t_node	*stack_a;
	int	i;

	stack_a = NULL;
	i = ac - 1;
	while (i >= 0)
	{
		add_front(&stack_a, new_node(ft_atoi(av[i])));
		i--;
	}
	return (stack_a);
}

void print_stack(t_node *stack)
{
	t_node *tmp = stack;
	if (!tmp) return;

	while (tmp != NULL)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
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
	ft_printf("stack_a before\n");
	print_stack(stack_a);
	sort(&stack_a, &stack_b, ac - 1);
	ft_printf("\nstack_a after\n");
	print_stack(stack_a);
	return (0);
}

