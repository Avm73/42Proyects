/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:39:57 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 14:31:46 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*get_vector(int digits, int neg);
static int		ft_pow(int number);
static int		count_digit(int nb);
static void		put_digit(int neg, int digits, char *s, long long int lnb);

char	*ft_itoa(int n)
{
	int				digits;
	long long int	lnb;
	char			*s;
	int				neg;

	lnb = n;
	neg = 1;
	if (lnb < 0)
	{
		neg = 2;
		lnb = lnb * -1;
	}
	digits = count_digit (lnb);
	s = get_vector(digits, neg);
	if (!s)
		return (NULL);
	put_digit (neg, digits, s, lnb);
	return (s);
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

static char	*get_vector(int digits, int neg)
{
	char	*s;

	s = (char *) malloc (digits * sizeof(char) + neg);
	if (s == NULL)
		return (NULL);
	return (s);
}

static void	put_digit(int neg, int digits, char *s, long long int lnb)
{
	int	i;

	i = 0;
	if (neg == 2)
		s[i++] = '-';
	while (digits != 0)
	{
		s[i++] = lnb / ft_pow (digits) + 48;
		lnb = lnb % ft_pow (digits--);
	}
	s[i] = '\0';
}
