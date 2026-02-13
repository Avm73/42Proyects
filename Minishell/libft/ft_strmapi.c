/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:26:44 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:11:43 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_vector(int len);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*t;

	i = 0;
	t = get_vector(ft_strlen((char *)s));
	if (t == NULL)
	{
		free(t);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		t[i] = f(i, s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}

static char	*get_vector(int len)
{
	char	*s;

	s = (char *)malloc(len * sizeof(char) + 1);
	if (s == NULL)
		return (NULL);
	return (s);
}
