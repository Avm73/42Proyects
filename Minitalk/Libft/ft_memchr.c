/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:14:01 by anvilla-          #+#    #+#             */
/*   Updated: 2025/01/22 16:57:06 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[50] = "holamundo";

	printf("memchr: %p\n", memchr(str, '\0', 20));
	printf("ft_memchr: %p\n", ft_memchr(str, '\0', 20));
	return (0);
}
*/
