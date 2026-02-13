/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:22 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/15 09:45:21 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen((char *)s1);
	i = 0;
	j = 0;
	while (set[j] != '\0')
	{
		while (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		while (s1[len - 1] == set[j] && s1[i])
		{
			len--;
			j = 0;
		}
		j++;
	}
	return (ft_substr(s1, i, len - i));
}
