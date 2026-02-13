/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:13:09 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:16:22 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_size(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

char	**copy_env_without(char **env, int index)
{
	char	**new_env;
	int		i;
	int		j;

	new_env = malloc(sizeof(char *) * env_size(env));
	if (!new_env)
		return (NULL);
	i = 0;
	j = 0;
	while (env[i])
	{
		if (i != index)
			new_env[j++] = env[i];
		else
			free(env[i]);
		i++;
	}
	new_env[j] = NULL;
	return (new_env);
}
