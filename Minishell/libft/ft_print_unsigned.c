/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:37:02 by jonamart          #+#    #+#             */
/*   Updated: 2024/04/11 17:40:18 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(char **s, t_reader *rd,
				unsigned int ui, long long int lnb);

int	ft_print_unsigned(unsigned int ui, t_reader *rd)
{
	int				count;
	long long int	lnb;
	char			*s;

	lnb = ui;
	count = 0;
	s = NULL;
	s = ft_itoa(lnb);
	check_flags(&s, rd, ui, lnb);
	if (*s)
		count += ft_putstring(s);
	free(s);
	return (count);
}

static void	check_flags(char **s, t_reader *rd, unsigned int ui,
				long long int lnb)
{
	if (rd->dot)
	{
		if (ft_mini_atoi(rd->max_w) == 0 && ui == 0)
		{
			free (*s);
			*s = NULL;
			*s = ft_strdup("");
		}
		if (ft_mini_atoi(rd->max_w) > (int)ft_strlen(*s))
			*s = ft_fill(*s, ft_mini_atoi(rd->max_w) - ft_strlen(*s), '0', 0);
		if (rd->zero)
			rd->number = 1;
	}
	else if (rd->zero)
	{
		if (ft_mini_atoi(rd->min_w) > (int)ft_strlen(*s))
			*s = ft_fill(*s, ft_mini_atoi(rd->min_w) - ft_strlen(*s), '0', 0);
	}
	if (rd->plus && lnb > 0)
		*s = ft_fill(*s, 1, '+', 0);
	if (rd->number && ft_mini_atoi(rd->min_w) > (int)ft_strlen(*s))
		*s = ft_fill(*s, ft_mini_atoi(rd->min_w) - ft_strlen(*s), ' ', 0);
	else if (rd->minus && ft_mini_atoi(rd->min_w) > (int)ft_strlen(*s))
		*s = ft_fill(*s, (ft_mini_atoi(rd->min_w) - ft_strlen(*s)), ' ', 1);
}
