/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 14:05:48 by anvilla-          #+#    #+#             */
/*   Updated: 2025/01/31 13:55:02 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (ptr);
	while (i < (nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
/*
int	main(void)
{
	printf("calloc: %d\n", calloc(5, 1));
	printf("ft_calloc: %d\n", ft_calloc(5, 1));
	return(0);
}
*/
