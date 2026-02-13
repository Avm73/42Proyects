/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:00:42 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/12 15:03:21 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sigint_child(int sig)
{
	if (sig == SIGINT)
		write(1, "\n", 1);
}

void	sigquit_child(int sig)
{
	if (sig == SIGQUIT)
		write(1, "Quit (core dumped)\n", 19);
}

void	sigint_heredoc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	exit(1);
}
