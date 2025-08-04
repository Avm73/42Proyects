/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:00:06 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/24 20:23:05 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdigit(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (size += ft_printchar('0'));
	if (n == -2147483648)
		return (size += ft_printstr("-2147483648"));
	if (n < 0)
	{
		size += ft_printchar('-');
		n = -n;
	}
	if (n > 0)
		size += ft_printunsigned((unsigned int)n);
	return (size);
}
