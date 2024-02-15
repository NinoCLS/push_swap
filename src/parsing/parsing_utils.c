/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:34 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/15 18:00:21 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void free_tabs(t_tabs *tabs)
{
	if (tabs->stack_a->array)
		free(tabs->stack_a->array);
	if (tabs->stack_b->array)
		free(tabs->stack_b->array);
	if (tabs->stack_a)
		free(tabs->stack_a);
	if (tabs->stack_b)
		free(tabs->stack_b);
	if (tabs)
		free(tabs);
}

void display_errors (char *msg, t_tabs *tabs)
{
	ft_putstr_fd("Error\n\n", 2);
	ft_putstr_fd(msg, 2);
	free_tabs(tabs);
	exit(1);
}

int	ft_strcmp(char	*s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (unsigned char)s1[i] - (unsigned char)s2[i];
}

int check_if_string_is_number(char *str)
{
	if (*str == '\0' || (*str == '-' && *(str + 1) == '\0'))
		return 0;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return 0;
		str++;
	}
	return (1);
}