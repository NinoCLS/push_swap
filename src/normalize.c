/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:09:34 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/11 14:44:57 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	lst_size(t_node *lst)
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

static void	bubble_sort_array(int *array, int size)
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

static void	copy_to_array(t_node *stack_a, int *arr)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		arr[i++] = stack_a->content;
		stack_a = stack_a->next;
	}
}

static void	apply_index(t_node **stack_a, int *arr, int size)
{
	t_node	*temp;
	int		i;

	temp = *stack_a;
	while (temp != NULL)
	{
		i = 0;
		while (i < size)
		{
			if (temp->content == arr[i])
			{
				temp->content = i;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	normalize(t_node **stack_a)
{
	int	size;
	int	*arr;

	size = lst_size(*stack_a);
	arr = (int *)malloc(size * sizeof(int));
	copy_to_array(*stack_a, arr);
	bubble_sort_array(arr, size);
	apply_index(stack_a, arr, size);
	free(arr);
}
