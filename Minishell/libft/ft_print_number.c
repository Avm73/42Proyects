/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:19:52 by jonamart          #+#    #+#             */
/*   Updated: 2024/04/11 17:06:30 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*check_zero(t_reader *rd, int nb, char *str, int min_w);
static char	*check_dot(t_reader *rd, char *s, int min_w);
static char	*prefix(t_reader *rd, long long int nb, char *str);

int	ft_print_number(long long int lnb, t_reader *rd)
{
	int				count;
	char			*str;

	count = 0;
	str = ft_itoa(lnb);
	if (rd->dot)
	{
		if (ft_mini_atoi(rd->max_w) == 0 && lnb == 0)
		{
			free(str);
			str = ft_strdup("");
		}
		str = check_dot(rd, str, ft_mini_atoi(rd->max_w));
	}
	else if (rd->zero)
		str = check_zero(rd, lnb, str, ft_mini_atoi(rd->min_w));
	str = prefix(rd, lnb, str);
	if (rd->number && ft_mini_atoi(rd->min_w) > (int)ft_strlen(str))
		str = ft_fill(str, ft_mini_atoi(rd->min_w) - ft_strlen(str), ' ', 0);
	else if (rd->minus && ft_mini_atoi(rd->min_w) > (int)ft_strlen(str))
		str = ft_fill(str, ft_mini_atoi(rd->min_w) - ft_strlen(str), ' ', 1);
	count += ft_putstring(str);
	free(str);
	return (count);
}

static char	*check_zero(t_reader *rd, int nb, char *str, int min_w)
{
	if ((min_w > (int)ft_strlen(str) && nb < 0)
		|| ((rd->plus || rd->space) && nb >= 0
			&& min_w > (int)ft_strlen(str)))
		str = ft_fill(str, min_w - ft_strlen(str) - 1, '0', 0);
	else if (min_w > (int)ft_strlen(str) && nb >= 0)
		str = ft_fill(str, min_w - ft_strlen(str), '0', 0);
	return (str);
}

static char	*check_dot(t_reader *rd, char *str, int max_w)
{
	if (max_w > (int)ft_strlen(str))
		str = ft_fill(str, max_w - ft_strlen(str), '0', 0);
	if (rd->zero)
		rd->number = 1;
	return (str);
}

static char	*prefix(t_reader *rd, long long int nb, char *str)
{
	if (nb < 0)
		str = ft_fill(str, 1, '-', 0);
	if (rd->plus && nb >= 0)
		str = ft_fill(str, 1, '+', 0);
	if (rd->space && nb >= 0)
		str = ft_fill(str, 1, ' ', 0);
	return (str);
}
