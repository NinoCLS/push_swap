/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/08 11:06:04 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	lst_size(t_node *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

void	bubble_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void copy_to_array(t_node *stack_a, int *arr)
{
	int i = 0;
	while (stack_a != NULL)
	{
		arr[i++] = stack_a->content;
		stack_a = stack_a->next;
	}
}


void apply_index(t_node **stack_a, int *arr, int size)
{
	t_node *temp = *stack_a;
	int i;

	while (temp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (temp->content == arr[i])
			{
				temp->content = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}
}

void normalize(t_node **stack_a)
{
	int size;
	int *arr;
	
	size = lst_size(*stack_a);
	arr =  (int *)malloc(size * sizeof(int));
	copy_to_array(*stack_a, arr);
	bubble_sort_array(arr, size);
	// Attribuer les index en fonction du tableau trié
	apply_index(stack_a, arr, size);
	free(arr); // Libérer la mémoire allouée pour le tableau
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
	ft_printf("stack_a before\n");
	print_stack(stack_a);
	sort(&stack_a, &stack_b, ac - 1);
	ft_printf("\nstack_a after\n");
	print_stack(stack_a);
	return (0);
}

