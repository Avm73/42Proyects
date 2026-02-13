/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:50:25 by jonamart          #+#    #+#             */
/*   Updated: 2024/04/11 18:23:17 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(char const *format, t_reader *rd, va_list ap);

int	ft_printf(char const *format, ...)
{
	int			count;
	t_reader	*rd;
	va_list		ap;

	va_start(ap, format);
	rd = NULL;
	rd = new_reader();
	if (!rd)
		return (-1);
	rd->number = 1;
	count = 0;
	count += check_format(format, rd, ap);
	va_end(ap);
	free_reader(&rd);
	free(rd);
	return (count);
}

static int	check_format(char const *format, t_reader *rd, va_list ap)
{
	int	count;

	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			read_format(&format, rd);
			count += print_format (*format, ap, rd);
			clear_reader(&rd);
		}
		else
			count += write (1, format, 1);
		format++;
	}
	return (count);
}
