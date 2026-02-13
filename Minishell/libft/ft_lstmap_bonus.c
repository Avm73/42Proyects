/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonamart <jonamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:07:51 by jonamart          #+#    #+#             */
/*   Updated: 2024/03/25 19:39:38 by jonamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new_node;
	void	*set_content;

	if (!lst || !f || !del)
		return (NULL);
	head = NULL;
	while (lst)
	{
		set_content = f(lst -> content);
		new_node = ft_lstnew(set_content);
		if (!new_node)
		{
			del(set_content);
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		lst = lst -> next;
	}
	return (head);
}
