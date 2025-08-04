/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:37:21 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/06 19:14:40 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *s, char c)
{
	int	i;
	int	count;
	int	neword;

	i = 0;
	count = 0;
	neword = 1;
	while (s[i] != '\0')
	{
		if (s[i] != c && neword == 1)
		{
			neword = 0;
			count++;
		}
		else if (s[i] == c)
			neword = 1;
		i++;
	}
	return (count);
}

static char	**free_strings(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	**fill_strings(char **str, char const *s, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c) && *s)
				len = ft_strlen(s);
			else if (*s)
				len = ft_strchr(s, c) - s;
			str[i] = ft_substr(s, 0, len);
			if (!str[i])
				return (free_strings(str));
			s += len;
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((countwords(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = fill_strings(split, s, c);
	return (split);
}
