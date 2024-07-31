/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gharazka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:49:05 by gharazka          #+#    #+#             */
/*   Updated: 2024/07/31 21:49:06 by gharazka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*node;

	if (!lst)
		return (NULL);
	root = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
			ft_lstdelone(node, del);
		ft_lstadd_back(&root, node);
		lst = lst->next;
	}
	return (root);
}
