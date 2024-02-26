/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/26 17:49:00 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// create stack 
t_list	*create_stack(char **av)
{
	t_list	*stack;
	t_list	*new;
	int		i;
	int		*num;

	stack = NULL;
	i = 0;
	while (av[i])
	{
		num = (int *)malloc(sizeof(int));
		*num = ft_atoi(av[i]);
		new = ft_lstnew(num);
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

void print_stack(t_list *stack)
{
	while (stack)
	{
		printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
}

int	main (int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	
	if (ac == 1)
		return (0);
	av++;
	check_args(av);
	stack_a = create_stack(av);
	stack_b = NULL;
	ft_printf("stack_a before\n");
	print_stack(stack_a);
	sort(&stack_a, &stack_b, ac - 1);
	ft_printf("\nstack_a after\n");
	print_stack(stack_a);
	return (0);
}
