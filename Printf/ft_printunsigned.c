/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:33:15 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/24 20:22:25 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += ft_printchar('0');
	else
	{
		if (n / 10 != 0)
			ft_printunsigned(n / 10);
		ft_printchar((n % 10) + '0');
		while (n > 0)
		{
			n /= 10;
			size++;
		}
	}
	return (size);
}
