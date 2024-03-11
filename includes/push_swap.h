/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:11:28 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/11 15:42:46 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define NB_ERROR "All arguments must be valid numbers. Please ensure no non-numeric characters are included"
# define DUPLICATE_NB_ERROR "Arguments must be unique. Duplicates have been detected."
# define LIMITS_NB_ERROR "One or more arguments exceed the allowed limits for an integer. Values must be between -2147483648 and 2147483647."

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				content;
} t_node;

/*errors*/
void display_errors (char *msg);

/*parsing*/
void	check_args(char **args);
int		ft_strcmp(char	*s1, char *s2);
int		check_if_string_is_number(char *str);

/*list utils*/
t_node	*new_node(int content);
void	lst_new(int content);
void	add_front(t_node **stack, t_node *new);
void	add_back(t_node **stack, t_node *new);
t_node	*pop_front(t_node **stack);
void	lst_clear(t_node **lst);
t_node	*lst_last(t_node *lst);

/*actions*/
void	push(t_node **dst, t_node **src, char *instructions);
void	reverse_rotate(t_node **stack, char *instructions);
void	rotate(t_node **stack, char *instructions);
void	swap(t_node *stack, char *instructions);

/*sort*/
void	sort(t_node **a, t_node **b, int size);
int		is_sorted(t_node **a);
void	sort_three(t_node **lst);
void	sort_four(t_node **a, t_node **b);
void	sort_five(t_node **a, t_node **b);
void	sort_three_helper(t_node *current, t_node *last, t_node **lst);
void	sort_three_complex_case(t_node **lst);
void	sort_three_reverse_case(t_node **lst);
int		find_min(t_node *lst);
int		find_max(t_node *lst);

/*normalize*/
void normalize(t_node **stack_a);

#endif