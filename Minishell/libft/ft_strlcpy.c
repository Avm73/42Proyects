/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 20:11:06 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/15 10:24:41 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	len;

	len = 0;
	if (dstsize == 0)
		return ((size_t)ft_strlen((char *)src));
	while (*(src + len) && --dstsize)
		*dst++ = *(src + len++);
	*dst = '\0';
	return ((size_t)ft_strlen((char *)src));
}
