/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:17:50 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/25 17:56:52 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	is_empty(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i] == 32 || argv[1][i] == '\t')
		i++;
	if (argv[1][i] == '\0')
		error_exit();
}

char	**get_split(int argc, char **argv)
{
	if (argv[1][0] == '\0')
		error_exit();
	is_empty(argv);
	if (argc == 2 && argv[1][0] != '\0')
		argv = ft_split(argv[1], ' ');
	if (!argv || !argv[0])
		free_split(argv);
	return (argv);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	argv = get_split(argc, argv);
	get_numbers(argc, argv, &stack_a);
	get_index(&stack_a, stack_size(stack_a));
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) <= 3)
			tiny_sort(&stack_a);
		if (stack_size(stack_a) == 4)
			sort_four(&stack_a, &stack_b);
		if (stack_size(stack_a) == 5)
			handle_five(&stack_a, &stack_b);
		if (stack_size(stack_a) > 5)
			radix_sort(&stack_a, &stack_b, stack_size(stack_a));
	}
	if (stack_a)
		free_stack(stack_a, argc, argv);
	return (0);
}
