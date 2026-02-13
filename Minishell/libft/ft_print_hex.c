/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:36:23 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:13:23 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*check_flags(t_reader *rd, char *str, long long int nbr, int cap);
static char	*check_dot(t_reader *rd, long long int nbr, char *str);
static char	*check_hash(t_reader *rd, char *str, int cap, long long int nbr);

int	ft_print_hex(unsigned long long int nbr, int cap, t_reader *rd)
{
	int		count;
	char	*s;

	count = 0;
	s = NULL;
	s = print_get_vector(count_number_hex(nbr));
	if (!s)
		return (-1);
	number_convert_hex (nbr, s, cap);
	s[count_number_hex(nbr)] = '\0';
	s = check_flags(rd, s, nbr, cap);
	if (*s)
		count += ft_putstring(s);
	free(s);
	return (count);
}

static char	*check_flags(t_reader *rd, char *s, long long int nbr, int cap)
{
	int		min_width;

	min_width = ft_mini_atoi(rd->min_w);
	if (rd->dot)
		s = check_dot(rd, nbr, s);
	else if (rd->zero)
	{
		if (min_width > (int)ft_strlen(s) && rd->hash && nbr > 0)
			s = ft_fill(s, min_width - (int)ft_strlen(s) - 2, '0', 0);
		else if (min_width > (int)ft_strlen(s))
			s = ft_fill(s, min_width - (int)ft_strlen(s), '0', 0);
	}
	s = check_hash(rd, s, cap, nbr);
	if (rd->number && min_width > (int)ft_strlen(s))
		s = ft_fill(s, min_width - (int)ft_strlen(s), ' ', 0);
	else if (rd->minus && min_width > (int)ft_strlen(s))
		s = ft_fill(s, (min_width - (int)ft_strlen(s)), ' ', 1);
	return (s);
}

static char	*check_dot(t_reader *rd, long long int nbr, char *str)
{
	char	*s;
	char	*aux;

	s = ft_strdup(str);
	if (ft_mini_atoi(rd->max_w) == 0 && nbr == 0)
	{
		free(s);
		s = NULL;
		s = ft_strdup("");
	}
	if (ft_mini_atoi(rd->max_w) > (int)ft_strlen(s))
		s = ft_fill(s, ft_mini_atoi(rd->max_w) - ft_strlen(s), '0', 0);
	if (rd->zero)
		rd->number = 1;
	aux = str;
	str = s;
	free(aux);
	return (str);
}

static char	*check_hash(t_reader *rd, char *s, int cap, long long int nbr)
{
	if (rd->hash && nbr != 0)
	{
		if (cap)
			s = ft_fill(s, 1, 'X', 0);
		else
			s = ft_fill(s, 1, 'x', 0);
		s = ft_fill(s, 1, '0', 0);
	}
	return (s);
}
