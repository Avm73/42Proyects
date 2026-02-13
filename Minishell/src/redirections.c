/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 16:00:27 by jonamart          #+#    #+#             */
/*   Updated: 2026/02/12 13:39:22 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	open_redir_file(t_redir *r, int *used_heredoc)
{
	if (r->type == TOKEN_REDIR_IN)
		return (open(r->file, O_RDONLY));
	if (r->type == TOKEN_REDIR_OUT)
		return (open(r->file, O_WRONLY | O_CREAT | O_TRUNC, 0644));
	if (r->type == TOKEN_REDIR_APPEND)
		return (open(r->file, O_WRONLY | O_CREAT | O_APPEND, 0644));
	if (r->type == TOKEN_HEREDOC)
	{
		if (*used_heredoc)
			return (-3);
		*used_heredoc = 1;
		return (r->heredoc_fd);
	}
	return (-1);
}

static int	get_target_fd(t_redir *r)
{
	if (r->type == TOKEN_REDIR_IN || r->type == TOKEN_HEREDOC)
		return (0);
	return (1);
}

int	apply_redirections(t_redir *r)
{
	int	fd;
	int	target_fd;
	int	used_heredoc;

	used_heredoc = 0;
	while (r)
	{
		fd = open_redir_file(r, &used_heredoc);
		if (fd == -3)
		{
			r = r->next;
			continue ;
		}
		if (fd < 0)
		{
			ft_printf("minishell: cannot open %s\n", r->file);
			return (-1);
		}
		target_fd = get_target_fd(r);
		if (dup2(fd, target_fd) < 0)
			return (-1);
		close(fd);
		r = r->next;
	}
	return (0);
}
