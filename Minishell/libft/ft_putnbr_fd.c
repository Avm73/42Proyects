/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:44:24 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:11:32 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int nb);
static int	ft_pow(int number);

void	ft_putnbr_fd(int n, int fd)
{
	int				digits;
	long long int	lnb;
	int				neg;

	lnb = n;
	neg = 0;
	if (lnb < 0)
	{
		neg = 1;
		lnb = lnb * -1;
	}
	digits = count_digit (lnb);
	if (neg)
		ft_putchar_fd ('-', fd);
	while (digits != 0)
	{
		ft_putchar_fd (lnb / ft_pow (digits) + 48, fd);
		lnb = lnb % ft_pow (digits--);
	}
}

static int	count_digit(int nb)
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

static int	ft_pow(int number)
{
	int	res;

	res = 1;
	while (number > 1)
	{
		res *= 10;
		number--;
	}
	return (res);
}
