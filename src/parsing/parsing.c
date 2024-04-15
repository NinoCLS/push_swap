/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:17:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/04/15 16:17:49 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	check_if_nb(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!check_if_string_is_number(args[i]))
			return (-1);
		i++;
	}
	return (1);
}

static int	check_if_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_limits(char **args)
{
	int		i;
	long	val;

	i = 0;
	while (args[i])
	{
		val = ft_atol(args[i]);
		if (val < INT_MIN || val > INT_MAX)
			return (-1);
		i++;
	}
	return (1);
}

void	check_args(char **args)
{
	if (check_if_nb(args) == -1)
		display_errors("Error\n");
	else if ((check_if_duplicate(args)) == -1)
		display_errors("Error\n");
	else if (check_limits(args) == -1)
		display_errors("Error\n");
}
