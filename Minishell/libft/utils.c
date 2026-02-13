/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:33:02 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:17:37 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstring("(null)"));
	while (*s)
		count += ft_putchar(*(s++));
	return (count);
}

int	count_digit(long long int nb)
{
	int	count;

	count = 1;
	while (nb / 10 != 0)
	{
		count++;
		nb = nb / 10;
	}
	return (count);
}

int	ft_pow(int number)
{
	long long int	res;

	res = 1;
	while (number > 1)
	{
		res *= 10;
		number--;
	}
	return (res);
}

int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}

char	*print_get_vector(int len)
{
	char	*s;

	s = (char *)malloc (len + 1 * sizeof(char));
	if (!s)
		return (NULL);
	return (s);
}
