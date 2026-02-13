/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:09:35 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/15 09:44:35 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*s;
	int					i;
	unsigned int		tot;

	tot = ft_strlen ((char *)s1) + ft_strlen ((char *)s2);
	s = (char *)malloc (tot * sizeof (char) + 1);
	if (s == NULL)
		return (s);
	i = 0;
	while (i < (int)tot)
	{
		if (i < (int)ft_strlen ((char *)s1))
			s[i] = s1[i];
		else
			s[i] = s2[i - (int)ft_strlen ((char *)s1)];
		i++;
	}
	s[i] = '\0';
	return (s);
}
