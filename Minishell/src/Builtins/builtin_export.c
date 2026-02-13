/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:25 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:09:46 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_export_identifier(const char *s)
{
	int	i;

	if (!s || (!ft_isalpha(s[0]) && s[0] != '_'))
		return (0);
	i = 1;
	while (s[i] && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	print_export_line(char *entry)
{
	char	*eq;

	eq = ft_strchr(entry, '=');
	if (eq)
	{
		*eq = '\0';
		ft_printf("declare -x %s=\"%s\"\n", entry, eq + 1);
		*eq = '=';
	}
	else
		ft_printf("declare -x %s\n", entry);
}

void	print_export(t_shell *sh)
{
	int	i;

	i = 0;
	while (sh->env[i])
	{
		print_export_line(sh->env[i]);
		i++;
	}
}

static int	process_export_arg(char *arg, t_shell *sh)
{
	char	*eq;

	if (!is_valid_export_identifier(arg))
	{
		ft_printf("minishell: export: `%s': not a valid identifier\n", arg);
		return (1);
	}
	eq = ft_strchr(arg, '=');
	if (eq)
	{
		*eq = '\0';
		set_env_value(arg, eq + 1, sh);
		*eq = '=';
	}
	else if (!get_env_value(arg, sh->env))
		set_env_value(arg, "", sh);
	return (0);
}

int	builtin_export(char **argv, t_shell *sh)
{
	int	i;
	int	status;

	if (!argv[1])
	{
		print_export(sh);
		return (0);
	}
	i = 1;
	status = 0;
	while (argv[i])
	{
		if (process_export_arg(argv[i], sh))
			status = 1;
		i++;
	}
	return (status);
}
