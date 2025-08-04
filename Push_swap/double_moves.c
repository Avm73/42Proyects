/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 20:37:39 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/13 19:30:12 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write(1, "ss\n", 3);
}

void	rr_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	write(1, "rr\n", 3);
}

void	rrr_reverse(t_stack **stack_a, t_stack **stack_b)
{
	reverse_ra(stack_a);
	reverse_rb(stack_b);
	write(1, "rrr\n", 4);
}
