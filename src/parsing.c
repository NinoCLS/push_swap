/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:17:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/12 16:49:06 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int check_if_nb(char **args)
{
	int i;
	
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
	if (ft_atoi(args[0]) == 2147483650)
		return (-1);
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == 2147483650 \
				|| ft_atoi(args[j]) == 2147483650)
				return (-1);
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

// int	check_limits()

void	handle_errors(char **args)
{
	if (check_if_nb(args) == -1)
		display_errors(NB_ERROR);
	if ((check_if_duplicate(args)) == -1)
		display_errors(DUPLICATE_NB_ERROR);
}