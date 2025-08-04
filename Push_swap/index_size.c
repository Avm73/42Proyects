/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:34:33 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/21 19:28:16 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	*sort_array(int *array, int size)
{
	int	i;
	int	swap;

	i = 1;
	while (i < size)
	{
		if (array[i] < array[i - 1])
		{
			swap = array[i - 1];
			array[i - 1] = array[i];
			array[i] = swap;
			i = 0;
		}
		i++;
	}
	return (array);
}

int	*get_array(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		*array;
	int		i;

	i = 0;
	tmp = *stack;
	array = (int *)malloc(size * sizeof(int));
	if (!array)
		return (NULL);
	while (i < size && tmp != NULL)
	{
		array[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (array);
}

void	get_index(t_stack **stack, int size)
{
	int		i;
	int		*array;
	t_stack	*tmp;

	tmp = *stack;
	i = 0;
	array = get_array(stack, size);
	array = sort_array(array, size);
	while (i < size)
	{
		while (tmp != NULL)
		{
			if (tmp->value == array[i])
				tmp->index = i;
			tmp = tmp->next;
		}
		tmp = *stack;
		i++;
	}
	free(array);
}
