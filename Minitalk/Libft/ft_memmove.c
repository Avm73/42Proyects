/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:15:34 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/03 18:12:58 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (((char *)dest) > ((char *)src))
	{
		while (n > 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main(void)
{
	char	str[50] = "holamundo";
	char	ptr[50] = "holamundo";

	memmove(str + 2, str, 20);
	printf("memmove: %s\n", str + 2);
	ft_memmove(ptr + 2, ptr, 20);
	printf("ft_memmove: %s\n", ptr + 2);
	return (0);
}
*/
