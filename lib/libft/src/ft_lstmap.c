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
