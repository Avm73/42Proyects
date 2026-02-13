/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:46:46 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/26 10:22:39 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*string;

	i = 0;
	string = (void *)s;
	while (i < n)
	{
		if (string[i] == (char)c)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
