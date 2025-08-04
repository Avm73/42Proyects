/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:22:05 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/25 17:59:34 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include "stdbool.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// *** Stack ***
t_stack		*create_node(int value);
void		create_stack(int argc, char **argv, t_stack **stack_a);
int			stack_size(t_stack *stack);

// *** Nodes ***
void		add_front(t_stack **stack, int value);
void		add_back(t_stack **stack, int value);
void		del_front(t_stack **stack);

// *** Free functions ***
void		free_stack(t_stack *stack, int argc, char **argv);
void		free_split(char **s);
void		print_stack(t_stack *stack);
int			main(int argc, char **argv);
void		error_exit(void);

// *** Validation ***
long int	ft_convert_argument(char *str);
void		is_empty(char **argv);
char		**get_split(int argc, char **argv);
int			ft_digits(char *argv);
int			is_super_overflow(char *str);
void		get_numbers(int argc, char **argv, t_stack **stack_a);
int			duplicate_value(t_stack *stack_a);

// *** Movements ***
void		swap_a(t_stack **head);
void		push_a(t_stack **head_a, t_stack **head_b);
void		rotate_a(t_stack **head);
void		reverse_ra(t_stack **head);
void		swap_b(t_stack **head);
void		push_b(t_stack **head_a, t_stack **head_b);
void		rotate_b(t_stack **head);
void		reverse_rb(t_stack **head);
void		ss_swap(t_stack **stack_a, t_stack **stack_b);
void		rr_rotate(t_stack **stack_a, t_stack **stack_b);
void		rrr_reverse(t_stack **stack_a, t_stack **stack_b);

// *** Index ***
int			*get_array(t_stack **stack, int size);
int			*sort_array(int *array, int size);
void		get_index(t_stack **stack, int size);
int			find_high_index(t_stack *stack);
int			find_min_index(t_stack *stack);

// *** Algoritm ***
int			is_sorted(t_stack *stack);
void		tiny_sort(t_stack **stack_a);
void		sort_four(t_stack **a, t_stack **b);
void		handle_five(t_stack **a, t_stack **b);
void		radix_sort(t_stack **a, t_stack **b, int size);
int			max_bits(int max_index);

#endif
