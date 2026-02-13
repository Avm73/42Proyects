/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:02:40 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/25 15:10:40 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	num;
	int	i;
	int	j;
	int	sign;

	j = 1;
	i = 0;
	sign = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (sign > 0)
			return (0);
		if (str[i] == '-' && sign == 0)
			j *= -1;
		sign++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return ((j * num));
}
