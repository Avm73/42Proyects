/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:01:38 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/08 19:10:55 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;

	i = 0;
	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (aux_s1[i] < aux_s2[i])
			return (-1);
		if (aux_s1[i] > aux_s2[i])
			return (1);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	str1[50] = "holamunda";
	char	str2[50] = "holamundA";

	printf("memcmp: %d\n", memcmp(str1, str2, 0));
	printf("ft_memcmp: %d\n", ft_memcmp(str1, str2, 0));
	return (0);
}
*/
