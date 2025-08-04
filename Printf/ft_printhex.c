/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:37:53 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/24 20:25:33 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_puthex(n % 16, format);
	}
	else
	{
		if (n < 10)
			ft_printchar(n + '0');
		else
		{
			if (format == 'x')
				ft_printchar(n - 10 + 'a');
			if (format == 'X')
				ft_printchar(n - 10 + 'A');
		}
	}
}

static int	ft_lenhex(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_printhex(unsigned int n, char format)
{
	int	size;

	size = 0;
	if (n == 0)
		return (size += ft_printchar('0'));
	else
	{
		ft_puthex(n, format),
		size += ft_lenhex(n);
	}
	return (size);
}
