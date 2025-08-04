/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_movements.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:56:50 by anvilla-          #+#    #+#             */
/*   Updated: 2025/06/22 21:30:47 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **head)
{
	t_stack	*n1;
	t_stack	*n2;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	n1 = *head;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	*head = n2;
	write(1, "sa\n", 3);
}

void	push_a(t_stack **head_a, t_stack **head_b)
{
	t_stack	*tmp;

	if (*head_b == NULL)
		return ;
	tmp = *head_b;
	*head_b = (*head_b)->next;
	tmp->next = *head_a;
	*head_a = tmp;
	write(1, "pa\n", 3);
}

void	rotate_a(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*n1;

	if ((*head == NULL) || (*head)->next == NULL)
		return ;
	n1 = *head;
	*head = n1->next;
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = n1;
	n1->next = NULL;
	write(1, "ra\n", 3);
}

void	reverse_ra(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*lst;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	while (tmp->next != NULL)
	{
		lst = tmp;
		tmp = tmp->next;
	}
	lst->next = NULL;
	tmp->next = *head;
	*head = tmp;
	write(1, "rra\n", 4);
}
