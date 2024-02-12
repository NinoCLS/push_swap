/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:44:48 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/12 12:01:27 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	display_errors(char *msg)
{
	ft_putstr_fd("Error\n\n", 2);
	ft_putstr_fd(msg, 2);
	exit(1);
}