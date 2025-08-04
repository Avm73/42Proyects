/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:29:01 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/08 16:26:06 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		f(i, (s + i));
		i++;
	}
}
/*
static void istoupper(unsigned int n, char *c)
{
	(void)n;
	if (*c >= 97 && *c <= 122)
		*c -= 32;
}
int main(void)
{
	char	str[] = "HolamuNDO\n";
	ft_putstr_fd(str, 1);
	ft_striteri(str, istoupper);
	ft_putstr_fd(str, 1);
	return (0);
}
*/
