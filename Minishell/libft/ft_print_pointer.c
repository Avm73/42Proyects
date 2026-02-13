/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:36:58 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:13:43 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(void *p, t_reader *rd)
{
	unsigned long long int	i;
	int						count;
	char					*s;

	count = 0;
	s = NULL;
	i = (unsigned long long int) p;
	s = print_get_vector (count_number_hex (i));
	if (!s)
		return (-1);
	number_convert_hex (i, s, 0);
	s[count_number_hex(i)] = '\0';
	s = ft_fill(s, 1, 'x', 0);
	s = ft_fill(s, 1, '0', 0);
	if (rd->number && ft_mini_atoi(rd->min_w) > (int)ft_strlen(s))
		s = ft_fill(s, ft_mini_atoi(rd->min_w) - ft_strlen(s), ' ', 0);
	else if (rd->minus && ft_mini_atoi(rd->min_w) > (int)ft_strlen(s))
		s = ft_fill(s, (ft_mini_atoi(rd->min_w) - ft_strlen(s)), ' ', 1);
	if (s)
		count = ft_putstring(s);
	free (s);
	return (count);
}
