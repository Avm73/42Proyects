/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 18:33:58 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/22 21:07:03 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits(int max_index)
{
	int	bits;

	bits = 0;
	while ((max_index >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b, int size)
{
	int	i;
	int	j;
	int	num;
	int	bits;

	i = 0;
	bits = max_bits(size - 1);
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*a)->index;
			if (((num >> i) & 1) == 0)
				push_b(a, b);
			else
				rotate_a(a);
			j++;
		}
		while (*b)
			push_a(a, b);
		i++;
	}
}
