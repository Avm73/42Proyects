/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:45:10 by jonamart          #+#    #+#             */
/*   Updated: 2024/04/11 18:24:28 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	read_first_flags(const char **format, t_reader *rd);
static void	fill_min_max(const char **format, int first_index,
				char *field_width);

void	read_format(const char **format, t_reader *rd)
{
	(*format)++;
	read_first_flags(format, rd);
	fill_min_max(format, 1, rd->min_w);
	if (**format == '.')
	{
		rd->dot = 1;
		(*format)++;
	}
	fill_min_max(format, rd->dot, rd->max_w);
}

static void	read_first_flags(const char **format, t_reader *rd)
{
	while (**format == '+' || **format == '#' || **format == ' '
		|| **format == '0' || **format == '-')
	{
		if (**format == '+')
		{
			rd->plus = 1;
			rd->space = 0;
		}
		else if (**format == ' ' && !rd->plus)
			rd->space = 1;
		else if (**format == '#')
			rd->hash = 1;
		if (**format == '-')
		{
			rd->minus = 1;
			rd->number = 0;
		}
		else if (**format == '0')
		{
			rd->zero = 1;
			rd->number = 0;
		}
		(*format)++;
	}
}

static void	fill_min_max(const char **format, int first_index,
				char *field_width)
{
	int	i;

	i = 0;
	while (**format >= '0' && **format <= '9')
	{
		if (first_index)
			field_width[i++] = **(format);
		(*format)++;
	}
	field_width[i] = '\0';
}
