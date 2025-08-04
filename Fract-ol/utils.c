/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:51:09 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/14 17:44:58 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 1;
	if (s1[0] >= 'a' && s1[0] <= 'z')
		s1[0] = ft_toupper(s1[0]);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	ft_atod(const char *str)
{
	double	res;
	double	decimal;
	int		sign;

	res = 0.0;
	decimal = 1.0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		res = res * 10 + (*str++ - '0');
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			decimal *= 0.1;
			res += (*str++ - '0') * decimal;
		}
	}
	return (res * sign);
}
