/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:29:56 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/13 18:51:36 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	char	**args;

	if (ac == 1)
		display_errors(ARG_ERROR);
	if (ac == 2)
		args = ft_split(av[1], WHITE_SPACE);
	else
	{
		args = av;
		args++;
	}
	int	i = 0;
	check_args(args);
}
