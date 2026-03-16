#include "push_swap.h"

// 4 functions
t_list	*ft_lstnew(long data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
// listsize
int	ft_lstsize(t_list *stack)
{
	size_t  count;

	count = 0;
	while(stack)
	{
		count = count + 1;
		stack = stack->next;
	}
	return (count);
}
// 新的node添加到第一个，need update 头指针
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

//新的node添加到最后一个
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *tmp;

	tmp = *lst;
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
