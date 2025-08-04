/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:52:14 by anvilla-          #+#    #+#             */
/*   Updated: 2025/07/02 20:53:10 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

volatile int	g_ack_received = 0;

void	ack_handler(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack_received = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack_received)
			usleep(1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int					server_pid;
	int					i;
	char				*str;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(2, "Usage: ./client <PID> <string>\n", 31);
		return (1);
	}
	sa.sa_handler = ack_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	i = 0;
	while (str[i])
	{
		send_char(server_pid, str[i]);
		i++;
	}
	send_char(server_pid, '\0');
	return (0);
}
