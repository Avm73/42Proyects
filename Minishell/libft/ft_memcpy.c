/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:13:43 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/26 09:40:09 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*cdst;
	char	*csrc;

	if (!src && !dst)
		return (NULL);
	i = 0;
	cdst = (char *)dst;
	csrc = (char *)src;
	while (n--)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
