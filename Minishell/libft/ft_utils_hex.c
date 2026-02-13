/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:52:49 by jonamart          #+#    #+#             */
/*   Updated: 2024/04/04 19:14:07 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	manage_neg_hex(long long int i)
{
	long long int	max;

	max = 4294967295;
	return (max + i + 1);
}

void	number_convert_hex(unsigned long long int num, char *s, int cap)
{
	static int		count;
	static char		*base;

	if (cap)
		base = "0123456789ABCDEF\0";
	else
		base = "0123456789abcdef\0";
	count = 0;
	if (num >= 16)
		number_convert_hex(num / 16, s, cap);
	s[count++] = base[num % 16];
}

int	count_number_hex(unsigned long long int num)
{
	static int	count;

	count = 0;
	if (num >= 16)
		count_number_hex(num / 16);
	count++;
	return (count);
}
