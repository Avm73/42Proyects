/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:24:13 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/14 13:11:58 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	int				i;
	unsigned char	uc;
	char			*cstr;

	i = 0;
	uc = (unsigned char)c;
	cstr = (char *)str;
	if (len <= 0)
		return (str);
	while (len > 0)
	{
		cstr[i] = uc;
		i++;
		len--;
	}
	return (cstr);
}
