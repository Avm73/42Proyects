/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:09:35 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:35:39 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	next_copy(int ini, char *sdest, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		sdest[ini + i] = s2[i];
		i++;
	}
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*res;
	int		tot;
	int		i;

	if (!s1 || !s2 || !s3)
		return (NULL);
	tot = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	res = malloc(tot + 1);
	if (!res)
		return (NULL);
	i = 0;
	next_copy(i, res, s1);
	i = ft_strlen(s1);
	next_copy(i, res, s2);
	i = i + ft_strlen(s2);
	next_copy(i, res, s3);
	res[tot] = '\0';
	return (res);
}
