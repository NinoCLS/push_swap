/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/15 17:54:23 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// int array_length(char **array)
// {
// 	int i = 0;

// 	while (array[i] != NULL)
// 		i++;
// 	return i;
// }

// int	main(int ac, char **av)
// {
// 	t_tabs tabs;
// 	char	**args;
// 	int	i;
// 	int	arg_count;

// 	tabs.stack_a = NULL;
// 	tabs.stack_b = NULL;
// 	if (ac == 1)
// 		return (0);
// 	if (ac == 2)
// 	{
// 		args = ft_split(av[1], WHITE_SPACE);
// 		arg_count = array_length(args);
// 		ft_printf("arg_count = %d\n", arg_count);
// 		tabs.stack_a = (int *)malloc(sizeof(int) * arg_count + 1);
// 		check_args(args, 1);
// 	}
// 	else
// 	{
// 		args = av;
// 		args++;
// 		arg_count = ac - 1;
// 		tabs.stack_a = (int *)malloc(sizeof(int) * arg_count + 1);
// 		check_args(args, 2);
// 	}
// 	i = 0;
// 	while (i < arg_count)
// 	{
// 		tabs.stack_a[i] = ft_atoi(args[i]);
// 		i++;
// 	}
// 	ft_printf("ok\n");
// 	// tabs.stack_a[i] = 0;
// 	free(tabs.stack_a);
// }


int	main (int ac, char **av)
{
	t_tabs tabs;
	int	i;
	
	tabs.stack_a = NULL;
	tabs.stack_b = NULL;
	if (ac == 1)
		return (0);
	tabs.stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!tabs.stack_a)
		return (1);
	tabs.stack_a->size = ac - 1;
	tabs.stack_a->array = (int *)malloc(sizeof(int) * (ac - 1));
	if (!tabs.stack_a->array)
	{
		free(tabs.stack_a);
		return (1);
	}
	av++;
	check_args(av, &tabs);
	i = 0;
	while (av[i])
	{
		tabs.stack_a->array[i] = ft_atoi(av[i]);
		i++;
	}
	// Don't forget to free memory when you're done
	// free(tabs.stack_a->array);
	// free(tabs.stack_a);
	return (0);
}