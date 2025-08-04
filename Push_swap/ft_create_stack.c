/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:45:52 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/25 17:58:29 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(int argc, char **argv, t_stack **stack_a)
{
	int			i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i] != NULL)
	{
		if (ft_convert_argument(argv[i]) < INT_MIN || \
		ft_convert_argument(argv[i]) > INT_MAX)
		{
			free_stack(*stack_a, argc, argv);
			error_exit();
		}
		if (argv[i] != NULL && *stack_a)
			add_back(stack_a, ft_convert_argument(argv[i]));
		if (!*stack_a)
			*stack_a = create_node(ft_convert_argument(argv[i]));
		i++;
	}
	return ;
}

void	free_stack(t_stack *stack, int argc, char **argv)
{
	t_stack	*tmp;

	if (argc == 2 && argv)
		free_split(argv);
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_split(char **s)
{
	int	i;

	i = 0;
	if (!s)
		error_exit();
	while (s[i] != NULL && *s)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int	is_super_overflow(char *str)
{
	char	*overflow_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	overflow_str = "18446744073709551616";
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i + j] == overflow_str[j] && overflow_str[j] != '\0')
		j++;
	if (j > 10)
		return (1);
	return (0);
}
