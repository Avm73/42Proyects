/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 20:00:19 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/08 19:25:18 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		str[i] = f(i, str[i]);
		i++;
	}
	return (str);
}
/*
char istoupper(unsigned int n, char c)
{
    (void)n;
    if (c >= 97 && c <= 122)
        c -= 32;
    return (c);
}

int main(void)
{
	char	*ptr = "Holamundo\n";
	char	*copy = ft_strmapi(ptr, istoupper);
	ft_putstr_fd(ptr, 1);
	ft_putstr_fd(copy, 1);
	return (0);
}
*/
