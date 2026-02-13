/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:51:20 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:14:26 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_reader	*new_reader(void)
{
	t_reader	*rd;

	rd = NULL;
	rd = (t_reader *)malloc (sizeof(t_reader));
	if (!rd)
		return (NULL);
	rd->min_w = print_get_vector(1024);
	if (!rd->min_w)
		return (NULL);
	rd->max_w = print_get_vector(1024);
	if (!rd->max_w)
		return (NULL);
	rd->space = 0;
	rd->dot = 0;
	rd->hash = 0;
	rd->minus = 0;
	rd->zero = 0;
	rd->plus = 0;
	rd->number = 0;
	return (rd);
}

void	free_reader(t_reader **rd)
{
	free ((*rd)->min_w);
	(*rd)->min_w = NULL;
	free ((*rd)->max_w);
	(*rd)->space = 0;
	(*rd)->dot = 0;
	(*rd)->hash = 0;
	(*rd)->minus = 0;
	(*rd)->zero = 0;
	(*rd)->plus = 0;
	(*rd)->number = 0;
}

void	clear_reader(t_reader **rd)
{
	(*rd)->space = 0;
	(*rd)->dot = 0;
	(*rd)->hash = 0;
	(*rd)->minus = 0;
	(*rd)->zero = 0;
	(*rd)->plus = 0;
	(*rd)->number = 1;
}
