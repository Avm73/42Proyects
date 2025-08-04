/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:35:18 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/04 19:16:19 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_printchar(ptr + '0');
		else
			ft_printchar(ptr - 10 + 'a');
	}
}

static int	ft_lenptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		len++;
		ptr /= 16;
	}
	return (len);
}

int	ft_printptr(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		return (ft_printstr("(nil)"));
	else
	{
		size += ft_printstr("0x");
		ft_putptr(ptr);
		size += ft_lenptr(ptr);
	}
	return (size);
}
