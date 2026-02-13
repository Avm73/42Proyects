/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 08:12:10 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/23 08:12:10 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 30
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int		found_newline(t_list *list);
t_list	*find_last_node(t_list *list);
char	*get_a_line(t_list *list);
void	put_line(t_list *list, char *str);
int		len_to_newline(t_list *list);
void	prepare_list(t_list **list);
char	*get_next_line(int fd);
void	dealloc(t_list **list, t_list *clean_node, char *buf);
void	create_list(t_list **list, int fd);

#endif
