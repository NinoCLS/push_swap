/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:11:28 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/26 17:12:07 by nclassea         ###   ########.fr       */
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
// }	t_elem;

// typedef struct s_stack 
// {
// 	int		size;
// 	t_elem	*head;
// }	t_stack;

/*actions*/

/*errors*/
void display_errors (char *msg);

/*parsing*/
void	check_args(char **args);
int		ft_strcmp(char	*s1, char *s2);
int		check_if_string_is_number(char *str);

/*actions*/
void	push(t_list **dst, t_list **src, char *instructions);
void	reverse_rotate(t_list **stack, char *instructions);
void	rotate(t_list **stack, char *instructions);
void	swap(t_list **stack, char *instructions);

/*sort*/
void	sort(t_list **a, t_list **b, int size);
void	a_is_sorted(t_list **a);

#endif