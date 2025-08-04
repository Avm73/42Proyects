/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:09:24 by anvilla-          #+#    #+#             */
/*   Updated: 2025/01/31 14:19:44 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (unsigned char)c)
	{
		i++;
	}
	if (s[i] == '\0' && s[i] != (unsigned char)c)
	{
		i++;
		return (NULL);
	}
	return ((char *)&s[i]);
}
/*
int	main(void)
{
	char	ptr[50] = "Holamundo";

	printf("strchr:%p\n", strchr(ptr, 'm'));
	printf("ft_strchr:%p\n", ft_strchr(ptr, 'm'));
	return (0);	
}
*/
