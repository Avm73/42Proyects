/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:57:00 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/12 16:26:02 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc_write_line(int fd, char *line, int expand, t_shell *sh)
{
	char	*exp;

	if (expand)
	{
		exp = expand_word(line, sh);
		write(fd, exp, ft_strlen(exp));
		free(exp);
	}
	else
		write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
}

void	run_heredoc_child(char *limiter, int expand, int write_fd, t_shell *sh)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strcmp(line, limiter))
		{
			free(line);
			close(write_fd);
			break ;
		}
		heredoc_write_line(write_fd, line, expand, sh);
		free(line);
	}
	close(write_fd);
	exit(0);
}
