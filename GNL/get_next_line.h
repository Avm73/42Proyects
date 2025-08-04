/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anvilla- <anvilla-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:55:12 by anvilla-          #+#    #+#             */
/*   Updated: 2025/04/13 20:19:20 by anvilla-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_file(int fd, char *buf);
char	*ft_exrtact_line(char *buf);
char	*ft_save(char *buf);
char	*ft_strjoin_and_free(char *buf, char *content);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t len, size_t size);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(char *s);

#endif
