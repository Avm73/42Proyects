/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:57:02 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/25 19:33:51 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*prenode;

	if (!lst || !del)
		return ;
	node = *lst;
	while (node)
	{
		prenode = node;
		node = node->next;
		del (prenode->content);
		free (prenode);
	}
	*lst = NULL;
}
