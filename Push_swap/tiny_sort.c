/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 18:39:05 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/22 21:31:05 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_high_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index > i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

int	find_min_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->index == i)
			i = stack->index;
		stack = stack->next;
	}
	return (i);
}

void	tiny_sort(t_stack **stack_a)
{
	int	high;

	high = find_high_index(*stack_a);
	if (*stack_a == NULL)
		error_exit();
	if ((*stack_a)->index == high)
		rotate_a(stack_a);
	else if ((*stack_a)->next->index == high)
		reverse_ra(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp->index != find_high_index(*a))
	{
		i++;
		tmp = tmp->next;
	}
	while ((*a)->index != find_high_index(*a) && *a)
	{
		if (i >= (stack_size(*a) / 2))
			reverse_ra(a);
		if (i < (stack_size(*a) / 2))
			rotate_a(a);
	}
	push_b(a, b);
	tiny_sort(a);
	push_a(a, b);
	rotate_a(a);
}

void	handle_five(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;
	int		min;

	min = find_min_index(*a);
	while (min < 2)
	{
		i = 1;
		tmp = *a;
		while (tmp->index != min)
		{
			i++;
			tmp = tmp->next;
		}
		while (i > (stack_size(*a) / 2) && (*a)->index != min)
			reverse_ra(a);
		while (i <= (stack_size(*a) / 2) && (*a)->index != min)
			rotate_a(a);
		push_b(a, b);
		min++;
	}
	tiny_sort(a);
	push_a(a, b);
	push_a(a, b);
}
