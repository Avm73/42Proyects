/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:07 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:09:39 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_env(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->env[i])
	{
		if (ft_strchr(sh->env[i], '='))
			ft_printf("%s\n", sh->env[i]);
		i++;
	}
	return (0);
}
