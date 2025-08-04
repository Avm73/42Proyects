/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:14:05 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/06 19:20:19 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst || !src)
		return (0);
	while (dst[i] != '\0' && i < size)
		i++;
	if (size != 0)
	{
		while (i + j < (size - 1) && src[j] != '\0')
		{
			dst[i + j] = src[j];
			j++;
		}
	}
	if (i < size)
		dst[i + j] = '\0';
	while (src[j] != '\0')
		j++;
	return (i + j);
}
/*
int	main(void)
{
	char	dst[50] = "hola";
	char	src[50] = "adios";

	printf("%zu\n", ft_strlcat(dst, src, 1));
	printf("%s\n", dst);
	return (0);
}
*/
