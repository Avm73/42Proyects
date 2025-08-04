/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:42:10 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/12 21:11:58 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del_front(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}

void	print_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		printf("value %d -> ", tmp->value);
		printf("index(%d) |", tmp->index);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
