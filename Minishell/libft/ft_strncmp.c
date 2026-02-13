/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:56:45 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/15 10:26:04 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while ((s1[c] | s2[c]) && (c != n))
	{
		if ((s1[c] - s2[c]) != 0)
		{
			return (((unsigned char)s1[c] - (unsigned char)s2[c]));
		}
		c++;
	}
	return (0);
}
