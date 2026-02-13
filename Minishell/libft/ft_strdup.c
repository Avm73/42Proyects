/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:49:01 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/15 10:24:24 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	char	*cs1;
	int		i;

	i = 0;
	cs1 = (char *)s1;
	cpy = (char *)malloc (ft_strlen (cs1) * sizeof (char) + 1);
	if (cpy == NULL)
		return (cpy);
	while (cs1[i])
	{
		cpy[i] = cs1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
