/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:17:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/14 16:08:53 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
static int check_limits(char **args)
{
	int i;
	int val;
	char *converted;

	i = 0;
	while (args[i])
	{
		val = ft_atoi(args[i]);
		converted = ft_itoa(val);

		if (ft_strcmp(args[i], converted) != 0)
		{
			free(converted);
			return (-1);
		}
		free(converted);
		i++;
	}
	return (1);
}


void	check_args(char **args, int nb)
{
	if (check_if_nb(args) == -1)
		display_errors(NB_ERROR, nb, args);
	else if ((check_if_duplicate(args)) == -1)
		display_errors(DUPLICATE_NB_ERROR, nb, args);
	else if (check_limits(args) == -1)
		display_errors(LIMITS_NB_ERROR, nb, args);
	else if (nb == 1)
		free_split_args(args);
}
