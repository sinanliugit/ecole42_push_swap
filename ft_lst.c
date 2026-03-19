/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:53:55 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 14:54:39 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_lstsize(t_list *stack)
{
	size_t	count;

	count = 0;
	while (stack)
	{
		count = count + 1;
		stack = stack->next;
	}
	return (count);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

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
