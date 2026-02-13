/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:14 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:09:43 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exit_numeric_error(char *arg)
{
	ft_printf("minishell: exit: %s: numeric argument required\n", arg);
	exit(255);
}

static int	exit_too_many_args(void)
{
	ft_printf("minishell: exit: too many arguments\n");
	return (1);
}

int	builtin_exit(char **argv, t_shell *sh)
{
	long	code;

	ft_printf("exit\n");
	if (!argv[1])
		exit(sh->last_status);
	if (!is_numeric(argv[1]))
		exit_numeric_error(argv[1]);
	if (argv[2])
		return (exit_too_many_args());
	code = ft_atoi(argv[1]);
	exit((unsigned char)code);
}
