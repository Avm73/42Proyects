/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:52:31 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/07 18:10:10 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(void)
{
	char	buffer[4096];

	if (getcwd(buffer, 4096))
	{
		ft_printf("%s\n", buffer);
		return (0);
	}
	ft_printf("minishell: pwd: error\n");
	return (1);
}
