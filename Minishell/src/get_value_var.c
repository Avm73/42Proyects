/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andres <andres@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:32:11 by andres            #+#    #+#             */
/*   Updated: 2026/02/04 12:33:43 by andres           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_value(char *name, t_shell *sh)
{
	int	i;
	int	len;

	len = ft_strlen(name);
	i = 0;
	while (sh->env[i])
	{
		if (!ft_strncmp(sh->env[i], name, len)
			&& sh->env[i][len] == '=')
			return (ft_strdup(sh->env[i] + len + 1));
		i++;
	}
	return (ft_strdup(""));
}
