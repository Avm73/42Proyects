/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:34:17 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/26 18:41:07 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*first;

	first = s;
	i = ft_strlen(s);
	s = (s + i);
	while (s != first && (unsigned char)c != *s)
		s--;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
