/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:34:43 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/26 19:00:50 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	fix_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen (s);
	if (start >= s_len)
	{
		res = malloc(1);
		if (res)
			res[0] = '\0';
		return (res);
	}
	if (s_len - start < len)
		fix_len = s_len - start;
	else
		fix_len = len;
	res = malloc (fix_len + 1);
	if (res)
	{
		ft_memcpy(res, (char *)s + start, fix_len);
		res[fix_len] = '\0';
	}
	return (res);
}
