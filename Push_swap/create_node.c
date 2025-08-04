/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:42:03 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/11 19:02:53 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_front(t_stack **stack, int value)
{
	t_stack	*new;

	new = create_node(value);
	new->next = *stack;
}

void	add_back(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = create_node(value);
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
