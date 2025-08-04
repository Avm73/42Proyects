/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:39:07 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/03 18:23:31 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	src_ptr[50] = "198237129873.298213731298712312879";
	char	dst_ptr[50] = "123";

	printf("ft_strlcpy: %zu\n", ft_strlcpy(dst_ptr, src_ptr, 14));
	//ft_strlcpy(dst_ptr, src_ptr, 8);
	//printf("%s",dst_ptr);
	return (0);
}
*/
