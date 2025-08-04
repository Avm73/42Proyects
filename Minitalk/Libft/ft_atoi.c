/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:55:59 by anvilla-          #+#    #+#             */
/*   Updated: 2025/01/23 16:30:35 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	n = 0;
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}
/*
int	main(void)
{
	printf("atoi: %d\n", atoi(" 	-+1234a"));
	printf("ft_atoi: %d\n", ft_atoi(" 	-+1234a"));
	return (0);
}
*/
