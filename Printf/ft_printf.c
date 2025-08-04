/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:32:54 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/23 18:37:30 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list ap, char format)
{
	int	size;

	size = 0;
	if (format == 'c')
		size += ft_printchar(va_arg(ap, int));
	else if (format == 's')
		size += ft_printstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		size += ft_printdigit(va_arg(ap, int));
	else if (format == 'u')
		size += ft_printunsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		size += ft_printhex(va_arg(ap, unsigned int), format);
	else if (format == 'p')
		size += ft_printptr(va_arg(ap, unsigned long long));
	else
		size += write(1, &format, 1);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;
	int		i;

	i = 0;
	size = 0;
	if (!format)
		return (0);
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			size += print_format(ap, format[i + 1]);
			i++;
		}
		else
			size += ft_printchar(format[i]);
		i++;
	}
	va_end(ap);
	return (size);
}

int	main(void)
{
	int	count = 0;
	int	size;

	count = ft_printf("%s", "hola");
	ft_printf("%d\n", count);
	size = printf("%s", "hiola");
	printf("%d\n", size);
	return (0);
}

