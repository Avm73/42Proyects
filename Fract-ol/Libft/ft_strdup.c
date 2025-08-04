/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:45:12 by anvilla-          #+#    #+#             */
/*   Updated: 2025/01/24 18:34:11 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*str;
	int		nmemb;
	int		i;

	i = 0;
	nmemb = ft_strlen(s);
	str = (char *)s;
	ptr = NULL;
	ptr = (char *)malloc((nmemb + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < nmemb)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
