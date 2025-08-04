/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:59:38 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/03 20:54:00 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		c_nbrs;
	long	nbr;

	c_nbrs = ft_countnbr(n);
	nbr = n;
	if (c_nbrs == 0)
		return (ft_strdup("0"));
	str = malloc((c_nbrs + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[c_nbrs] = '\0';
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr > 0)
	{
		c_nbrs--;
		str[c_nbrs] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
/*
int	main(void)
{
	printf("strnbr: %s\n", ft_itoa(-2147483648));
	return (0);
}
*/
