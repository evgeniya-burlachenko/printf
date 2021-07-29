#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*res;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	res = ft_lstlast(*lst);
	res->next = new;
}
