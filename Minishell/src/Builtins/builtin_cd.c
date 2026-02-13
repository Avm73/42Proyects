/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:51:38 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:09:33 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*cd_get_target(char **argv, t_shell *sh)
{
	char	*target;

	if (!argv[1])
		return (get_env_value("HOME", sh->env));
	if (!ft_strcmp(argv[1], "-"))
	{
		target = get_env_value("OLDPWD", sh->env);
		if (!target)
		{
			ft_printf("minishell: cd: OLDPWD not set\n");
			return (NULL);
		}
		ft_printf("%s\n", target);
		return (target);
	}
	return (argv[1]);
}

static void	cd_update_pwd(t_shell *sh, char *oldpwd)
{
	char	*newpwd;

	if (oldpwd[0] != '\0')
		set_env_value("OLDPWD", oldpwd, sh);
	newpwd = getcwd(NULL, 0);
	if (newpwd)
	{
		set_env_value("PWD", newpwd, sh);
		free(newpwd);
	}
}

int	builtin_cd(char **argv, t_shell *sh)
{
	char	oldpwd[4096];
	char	*target;
	char	*err_msg;

	if (!getcwd(oldpwd, sizeof(oldpwd)))
		oldpwd[0] = '\0';
	target = cd_get_target(argv, sh);
	if (!target || chdir(target) != 0)
	{
		err_msg = target;
		if (!target)
			err_msg = "";
		ft_printf("minishell: cd: %s: No such file or directory\n", err_msg);
		return (1);
	}
	cd_update_pwd(sh, oldpwd);
	return (0);
}
