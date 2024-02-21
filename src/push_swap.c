/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/21 17:34:23 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main (int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	
	if (ac == 1)
		return (0);
	av++;
	check_args(av);
	return (0);
}

void	init_stack(t_stack *stack_a, t_stack *stack_b, char **av, int ac)
{
	int	i;
	t_elem	*tmp;

	stack_a->head = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->size = 0;
	i = ac - 1;
	while (i >= 0)
	{
		tmp = malloc(sizeof(t_elem));
		if (!tmp)
			display_errors("Malloc failed\n");
		tmp->value = ft_atoi(av[i]);
		tmp->next = stack_a->head;
		stack_a->head = tmp;
		stack_a->size++;
		i--;
	}
}