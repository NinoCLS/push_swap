/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:11:28 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/15 17:46:28 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define WHITE_SPACE 32

# define NB_ERROR "All arguments must be valid numbers. Please ensure no non-numeric characters are included"
# define DUPLICATE_NB_ERROR "Arguments must be unique. Duplicates have been detected."
# define LIMITS_NB_ERROR "One or more arguments exceed the allowed limits for an integer. Values must be between -2147483648 and 2147483647."


// typedef struct s_elem
// {
// 	int				value;
// 	int				index;
// 	struct s_elem 	*next;
// 	struct s_elem 	*prev;
// } t_elem;


typedef struct s_stack
{
	int		*array;
	int		size;
} t_stack;

typedef struct s_tabs
{
	t_stack	*stack_a;
	t_stack	*stack_b;
} t_tabs;

/*actions*/

/*errors*/
void display_errors (char *msg, t_tabs *tabs);

/*parsing*/
void	check_args(char **args, t_tabs *tabs);
int		ft_strcmp(char	*s1, char *s2);
int		check_if_string_is_number(char *str);
void	free_split_args(char **args);

#endif