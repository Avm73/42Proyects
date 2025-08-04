/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:07:21 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/03 17:50:00 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	d[50] = "123456789";

	memcpy(d + 2, d, 48);
	printf("memcpy: %s\n", d + 2);
	ft_memcpy(d + 2, d, 48);
	printf("ft_memcpy: %s\n", d + 2);
	return (0);
}
*/
