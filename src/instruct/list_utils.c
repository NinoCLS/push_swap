/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:48:46 by nclassea          #+#    #+#             */
/*   Updated: 2024/03/11 15:41:17 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*new_node(int content)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	add_front(t_node **head, t_node *new_node)
{
	if (head == NULL || new_node == NULL)
		return ;
	new_node->next = *head;
	*head = new_node;
}

t_node	*lst_last(t_node *lst)
{
	t_node	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_node	*pop_front(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || stack == NULL)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

void	lst_clear(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
	*lst = NULL;
}
