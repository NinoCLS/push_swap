/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:58:34 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/14 16:08:47 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void free_split_args(char **args)
{
	int i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	display_errors(char *msg, int nb, char **args)
{
	if (nb == 1)
	{
		ft_putstr_fd("Error\n\n", 2);
		ft_putstr_fd(msg, 2);
		free_split_args(args);
		exit(1);
	}
	else if (nb == 2)
	{
		ft_putstr_fd("Error\n\n", 2);
		ft_putstr_fd(msg, 2);
		exit(1);
	}
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