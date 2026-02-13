/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 12:37:03 by jonamart          #+#    #+#             */
/*   Updated: 2024/04/11 17:24:19 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str, t_reader *rd)
{
	int		count;
	char	*s;

	count = 0;
	if (!str)
		s = ft_strdup("(null)");
	else
		s = ft_strdup(str);
	if (!s)
		return (-1);
	if (rd->dot && ft_mini_atoi(rd->max_w) < (int)ft_strlen(s))
		s = ft_cut(s, ft_mini_atoi(rd->max_w));
	if (rd->number && ft_mini_atoi(rd->min_w) > (int)ft_strlen(s))
		s = ft_fill(s, ft_mini_atoi(rd->min_w) - ft_strlen(s), ' ', 0);
	else if (rd->minus && ft_mini_atoi(rd->min_w) > (int)ft_strlen(s))
		s = ft_fill(s, (ft_mini_atoi(rd->min_w) - ft_strlen(s)), ' ', 1);
	if (*s)
		count += ft_putstring(s);
	free(s);
	return (count);
}
