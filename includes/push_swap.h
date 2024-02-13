/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:11:28 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/13 18:53:05 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define WHITE_SPACE 32

# define ARG_ERROR "An argument is missing"
# define NB_ERROR "All arguments must be valid numbers. Please ensure no non-numeric characters are included"
# define DUPLICATE_NB_ERROR "Arguments must be unique. Duplicates have been detected."
# define LIMITS_NB_ERROR "One or more arguments exceed the allowed limits for an integer. Values must be between -2147483648 and 2147483647."


# define INT_MIN -2147483648
# define INT_MAX 2147483647
// typedef struct s_elem
// {
	
// } t_elem;

void	display_errors(char *msg);


/*parsing*/
void	check_args(char **args);
int		ft_strcmp(char	*s1, char *s2);
int		check_if_string_is_number(char *str);

#endif