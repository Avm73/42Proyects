/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:11:04 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/25 17:54:36 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_digits(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argv[i] == '\0')
		return (1);
	while (argv[j] != '\0')
	{
		if (argv[j] == '-' || argv[j] == '+')
			j++;
		if (argv[j] < 48 || argv[j] > 57)
			return (1);
		j++;
	}
	return (0);
}

long int	ft_atol(const char *str)
{
	int			i;
	long int	n;
	int			sign;

	i = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (i > 1)
		return (LONG_MAX);
	n = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (LONG_MAX);
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

long int	ft_convert_argument(char *str)
{
	long int	value;

	value = ft_atol(str);
	return (value);
}

void	get_numbers(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 1;
	if (!argv)
		error_exit();
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if ((is_super_overflow(argv[i]) == 1) || (ft_digits(argv[i]) == 1))
		{
			if (argc == 2)
				free_split(argv);
			error_exit();
		}
		i++;
	}
	create_stack(argc, argv, stack_a);
	if (duplicate_value(*stack_a) == 1)
	{
		free_stack(*stack_a, argc, argv);
		error_exit();
	}
}

int	duplicate_value(t_stack *stack_a)
{
	t_stack	*tmp;
	t_stack	*dup;

	tmp = stack_a;
	while (tmp != NULL)
	{
		dup = tmp->next;
		while (dup != NULL)
		{
			if (dup->value == tmp->value)
				return (1);
			dup = dup->next;
		}
		tmp = tmp->next;
	}
	return (0);
}
