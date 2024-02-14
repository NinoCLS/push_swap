/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/14 14:54:06 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int	main(int ac, char **av)
{
	char	**args;

	if (ac == 1)
		return (0);
	if (ac == 2)
	{
		args = ft_split(av[1], WHITE_SPACE);
		check_args(args, 1);
	}
	else
	{
		args = av;
		args++;
		check_args(args, 2);
	}
}
