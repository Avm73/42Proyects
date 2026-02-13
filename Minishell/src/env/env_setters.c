/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:56:26 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:40:02 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replace_env_value(t_shell *sh, char *new_var, int i)
{
	free(sh->env[i]);
	sh->env[i] = new_var;
}

static void	append_env_value(t_shell *sh, char *new_var, int i)
{
	char	**new_env;
	int		j;

	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return ;
	j = 0;
	while (j < i)
	{
		new_env[j] = sh->env[j];
		j++;
	}
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(sh->env);
	sh->env = new_env;
}

void	set_env_value(const char *name, const char *value, t_shell *sh)
{
	char	*new_var;
	int		i;
	int		len;

	if (!*value)
		value = "";
	len = ft_strlen(name);
	new_var = ft_strjoin3((char *)name, "=", (char *)value);
	i = 0;
	while (sh->env[i])
	{
		if (!ft_strncmp(sh->env[i], name, len) && sh->env[i][len] == '=')
			return (replace_env_value(sh, new_var, i));
		i++;
	}
	append_env_value(sh, new_var, i);
}

int	unset_env_value(const char *key, t_shell *sh)
{
	char	**new_env;
	int		i;
	int		j;
	int		index;

	index = find_key_index(sh->env, key);
	if (index < 0)
		return (0);
	i = 0;
	while (sh->env[i])
		i++;
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		return (1);
	i = 0;
	j = 0;
	while (sh->env[i])
	{
		if (i != index)
			new_env[j++] = sh->env[i];
		else
			free(sh->env[i]);
		i++;
	}
	return (new_env[j] = NULL, free(sh->env), sh->env = new_env, 0);
}
