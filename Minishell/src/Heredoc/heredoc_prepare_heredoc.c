/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_prepare_heredoc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:57:17 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/12 13:31:56 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	copy_heredoc_to_pipe(int fd, int write_fd)
{
	char	buf[1024];
	int		n;

	n = read(fd, buf, sizeof(buf));
	while (n > 0)
	{
		write(write_fd, buf, n);
		n = read(fd, buf, sizeof(buf));
	}
	close(fd);
	return (0);
}

static int	process_single_heredoc(t_redir *r, int *hd_pipe, \
	int *has_hd, t_shell *sh)
{
	int	fd;

	signal(SIGINT, SIG_IGN);
	fd = handle_heredoc(r->file, !r->quoted, sh);
	signal(SIGINT, sigint_handler);
	if (fd == -2)
		return (-2);
	if (fd < 0)
		return (-1);
	if (!*has_hd)
	{
		if (pipe(hd_pipe) < 0)
		{
			close(fd);
			return (-1);
		}
		*has_hd = 1;
	}
	copy_heredoc_to_pipe(fd, hd_pipe[1]);
	return (0);
}

static void	update_hd_fd(t_redir *r, int fd)
{
	while (r)
	{
		if (r->type == TOKEN_HEREDOC)
			r->heredoc_fd = fd;
		r = r->next;
	}
}

int	prepare_heredocs(t_cmd *cmds, t_shell *sh)
{
	t_redir	*r;
	int		hd_pipe[2];
	int		has_hd;
	int		ret;

	while (cmds)
	{
		has_hd = 0;
		r = cmds->redirs;
		while (r)
		{
			if (r->type == TOKEN_HEREDOC)
			{
				ret = process_single_heredoc(r, hd_pipe, &has_hd, sh);
				if (ret < 0)
					return (ret);
			}
			r = r->next;
		}
		if (has_hd)
			(close(hd_pipe[1]), update_hd_fd(cmds->redirs, hd_pipe[0]));
		cmds = cmds->next;
	}
	return (0);
}
