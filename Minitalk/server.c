/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 19:56:41 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/04 12:59:13 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	*g_str;

void	fill_global(char c)
{
	char	tmp[2];
	char	*new_str;

	tmp[0] = c;
	tmp[1] = '\0';
	new_str = ft_strjoin(g_str, tmp);
	free(g_str);
	g_str = new_str;
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	curr_char = 0;
	static int				bit_index = 0;
	int						client_pid;

	(void)context;
	client_pid = info->si_pid;
	curr_char <<= 1;
	if (sig == SIGUSR2)
		curr_char |= 1;
	bit_index++;
	kill(client_pid, SIGUSR1);
	if (bit_index == 8)
	{
		if (curr_char == '\0')
		{
			write (1, g_str, ft_strlen(g_str));
			write(1, "\n", 1);
			free(g_str);
			g_str = ft_strdup("");
		}
		else
			fill_global(curr_char);
		curr_char = 0;
		bit_index = 0;
	}
}

void	sa_iniciate(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "sigaction SIGUSR1", 17);
		return ;
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "sigaction SIGUSR2", 17);
		return ;
	}
}

void	exit_handler(int sig)
{
	(void)sig;
	if (g_str)
		free(g_str);
	exit(0);
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		write(2, "Use ./server only", 17);
		return (1);
	}
	write(1, "Server PID: ", 12);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGINT, exit_handler);
	g_str = ft_strdup("");
	sa_iniciate();
	while (1)
		pause();
	return (0);
}
