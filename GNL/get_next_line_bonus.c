/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:39:27 by anvilla-          #+#    #+#             */
/*   Updated: 2025/04/16 18:43:44 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_save(char *buf)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		return (free(buf), NULL);
	rest = ft_calloc((ft_strlen(buf) - i + 1), 1);
	i++;
	j = 0;
	while (buf[i] != '\0')
		rest[j++] = buf[i++];
	free(buf);
	return (rest);
}

char	*ft_extract_line(char *buf)
{
	char	*line;
	size_t	i;

	i = 0;
	if (buf[i] == '\0')
		return (NULL);
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	line = ft_calloc(i + 2, 1);
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i])
		line[i] = buf[i];
	return (line);
}

char	*ft_strjoin_and_free(char *buf, char *content)
{
	char	*new;

	new = ft_strjoin(buf, content);
	free(buf);
	return (new);
}

char	*read_file(int fd, char *buf)
{
	ssize_t	byte_read;
	char	*content;

	if (!buf)
		buf = ft_calloc(1, 1);
	content = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!content)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, content, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(content), free(buf), NULL);
		content[byte_read] = '\0';
		buf = ft_strjoin_and_free(buf, content);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(content);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf[fd] = read_file(fd, buf[fd]);
	if (buf[fd] == NULL)
		return (NULL);
	line = ft_extract_line(buf[fd]);
	buf[fd] = ft_save(buf[fd]);
	return (line);
}
