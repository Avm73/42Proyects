/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:12:05 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/23 08:12:05 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*next_line;
	t_list			*prenode;
	static t_list	*list[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	{
		while (list[fd])
		{
			prenode = list[fd];
			list[fd] = list[fd]->next;
			free (prenode);
		}
		list[fd] = NULL;
		return (NULL);
	}
	create_list(&list[fd], fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = NULL;
	next_line = get_a_line(list[fd]);
	prepare_list(&list[fd]);
	return (next_line);
}

void	prepare_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;

	clean_node = malloc(sizeof(t_list));
	if (clean_node == NULL)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		clean_node->content[k++] = last_node->content[i];
	clean_node->content[k] = '\0';
	clean_node->next = NULL;
	dealloc(list, clean_node);
}

char	*get_a_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (!next_str)
		return (NULL);
	put_line(list, next_str);
	return (next_str);
}

void	add_end_list(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;
	int		i;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL )
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	i = 0;
	while (buf[i])
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		readed;	
	char	buf[BUFFER_SIZE + 1];

	while (!found_newline(*list))
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (!readed)
			return ;
		buf[readed] = '\0';
		add_end_list(list, buf);
	}
}
