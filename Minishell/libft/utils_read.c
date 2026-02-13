/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 10:55:12 by jonamart          #+#    #+#             */
/*   Updated: 2024/10/16 15:40:36 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_fill(char *s, int n, int c, int fin)
{
	int		i;
	char	*r;
	char	*tmp;

	r = NULL;
	tmp = NULL;
	r = print_get_vector(n);
	if (!r)
		return (NULL);
	i = 0;
	while (i < n)
		r[i++] = c;
	r[i] = '\0';
	if (fin)
		tmp = ft_strjoin(s, r);
	else
		tmp = ft_strjoin(r, s);
	free(r);
	r = s;
	s = tmp;
	free(r);
	return (s);
}

char	*ft_cut(char *s, int n)
{
	int		i;
	char	*res;
	char	*tmp;

	res = print_get_vector(n);
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	tmp = s;
	s = res;
	free(tmp);
	return (s);
}
