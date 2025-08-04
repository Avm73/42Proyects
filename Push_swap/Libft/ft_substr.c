/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:57:48 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/05 20:21:11 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s || len == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	if (len + start > ft_strlen(s))
		str = malloc((len) * sizeof(char));
	else
		str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char	str[50] = "hola asdf adfae ";
	char	*a;
	
	a = ft_substr(str, 2, 5);
	printf("%s\n", a);
	return (0);
}
*/