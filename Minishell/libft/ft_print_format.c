/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:59:06 by jonamart          #+#    #+#             */
/*   Updated: 2024/04/11 11:54:40 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char format, va_list ap, t_reader *rd)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_print_char(va_arg(ap, int), rd);
	else if (format == 's')
		count += ft_print_string (va_arg(ap, char *), rd);
	else if (format == 'i' || format == 'd')
		count += ft_print_number (va_arg(ap, int), rd);
	else if (format == 'x')
		count += ft_print_hex(va_arg(ap, unsigned int), 0, rd);
	else if (format == 'X')
		count += ft_print_hex(va_arg(ap, unsigned int), 1, rd);
	else if (format == '%')
		count += ft_print_percent('%', rd);
	else if (format == 'p')
		count += ft_print_pointer (va_arg(ap, void *), rd);
	else if (format == 'u')
		count += ft_print_unsigned (va_arg(ap, unsigned int), rd);
	else
		count += write (1, &format, 1);
	return (count);
}
