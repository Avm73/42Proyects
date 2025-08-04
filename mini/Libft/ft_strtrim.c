/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:28:41 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/08 18:41:04 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	while (end > start && (ft_isinset(s1[end], set)))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
/*
int main(void)
{
	char	*ptr;
	char	isset;
	char	*str;

	ptr = NULL;
	isset = ' ';
	str = ft_strtrim(ptr, &isset);
	printf("%s\n", str);
	return (0);
}
*/
