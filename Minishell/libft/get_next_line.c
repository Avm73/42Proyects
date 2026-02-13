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

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;
	t_list			*prenode;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next_line, 0) < 0)
	{
		while (list)
		{
			prenode = list;
			list = list->next;
			free (prenode->content);
			free (prenode);
		}
		list = NULL;
		return (NULL);
	}
	create_list(&list, fd);
	if (list == NULL)
		return (NULL);
	next_line = NULL;
	next_line = get_a_line(list);
	prepare_list(&list);
	return (next_line);
}

void	prepare_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (NULL == buf || NULL == clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	k = 0;
	while (last_node->content[i] && last_node->content[i] != '\n')
		++i;
	while (last_node->content[i] && last_node->content[++i])
		buf[k++] = last_node->content[i];
	buf[k] = '\0';
	clean_node->content = buf;
	clean_node->next = NULL;
	dealloc(list, clean_node, buf);
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

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL )
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->content = buf;
	new_node->next = NULL;
}

void	create_list(t_list **list, int fd)
{
	int		readed;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		readed = read(fd, buf, BUFFER_SIZE);
		if (!readed)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_end_list(list, buf);
	}
}
