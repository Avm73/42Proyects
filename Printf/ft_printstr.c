/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:51:02 by anvilla-          #+#    #+#             */
/*   Updated: 2025/02/25 12:57:29 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	size;

	size = 0;
	if (str == 0)
		return (ft_printstr("(null)"));
	while (*str)
	{
		size += ft_printchar(*str);
		str++;
	}
	return (size);
}
