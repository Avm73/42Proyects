/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:22:21 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/26 10:50:08 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	over_lap_copy( char *dst, char *src, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cdst;
	char	*csrc;

	if (! dst && ! src)
		return (NULL);
	cdst = (char *)dst;
	csrc = (char *)src;
	over_lap_copy (cdst, csrc, len);
	return (dst);
}

static void	over_lap_copy( char *dst, char *src, size_t len)
{
	size_t	i;

	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dst[i] = src[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
}
