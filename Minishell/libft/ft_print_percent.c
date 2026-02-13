/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:26:30 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:13:37 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put(t_reader *rd, int c);

int	ft_print_percent(int c, t_reader *rd)
{
	int		count;

	count = 0;
	if (ft_mini_atoi(rd->min_w) <= 1)
		count = write(1, &c, 1);
	else
		count = put(rd, c);
	return (count);
}

static int	put(t_reader *rd, int c)
{
	int		count;
	char	*s;

	s = NULL;
	count = 0;
	s = print_get_vector(0);
	if (!s)
		return (0);
	s[0] = '\0';
	if (rd->number)
	{
		s = ft_fill(s, ft_mini_atoi(rd->min_w) - 1, ' ', 0);
		count += ft_putstring(s);
		count += write (1, &c, 1);
	}
	else if (rd->minus)
	{
		s = ft_fill(s, ft_mini_atoi(rd->min_w) - 1, ' ', 1);
		count += write (1, &c, 1);
		count += ft_putstring(s);
	}
	free(s);
	return (count);
}
