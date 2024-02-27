/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:48:46 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/27 17:23:58 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node *new_node(int content)
{
    t_node *node = malloc(sizeof(t_node));
    if (node == NULL)
        return NULL;
    node->content = content;
    node->next = NULL;
    return node;
}

void add_back(t_node **stack_a, t_node *new_node)
{
	t_node *last_node;

	if (*stack_a == NULL)
	{
		*stack_a = new_node;
	}
	else
	{
		last_node = *stack_a;
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}


void add_front(t_node **head, t_node *new_node)
{
    if (head == NULL || new_node == NULL)
        return;
    new_node->next = *head;
    *head = new_node;
}


t_node	*pop_front(t_node **stack)
{
	t_node	*tmp;

	if (!(*stack) || stack == NULL) // S'assurer que la liste n'est pas vide
		return (NULL);
	tmp = *stack; // Sauvegarder le nœud à retirer
	*stack = (*stack)->next; // Mettre à jour le début de la liste
	if (*stack) // S'il reste des nœuds dans la liste
		(*stack)->prev = NULL;
	tmp->next = NULL; // Déconnecter le nœud retiré de la liste

	return (tmp); // Retourner le nœud retiré
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

