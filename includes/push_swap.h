/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:11:28 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/12 15:59:34 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define WHITE_SPACE 32

# define ARG_ERROR "An argument is missing"
# define NB_ERROR "One or some arguments are false"
# define DUPLICATE_NB_ERROR "duplicate"

// typedef struct s_elem
// {
	
// } t_elem;

void	display_errors(char *msg);


/*parsing*/
void	handle_errors(char **args);
int		ft_strcmp(char	*s1, char *s2);
int		check_if_string_is_number(char *str);

#endif