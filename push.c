/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:56:32 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 16:03:42 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//取出源栈顶元素；插入目标栈顶；更新链表指针
void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, tmp);
}

// push from a to b
void	pb(t_list **astack, t_list **bstack)
{
	push(astack, bstack);
	write(1, "pb\n", 3);
}

// push from b to a
void	pa(t_list **astack, t_list **bstack)
{
	push(bstack, astack);
	write(1, "pa\n", 3);
}

// void	print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		printf("%ld -> ", stack->data);
// 		stack = stack->next;
// 	}
// 	printf("NULL\n");
// }

// int		main(void)
// {
// 	t_list	*astack = NULL;
// 	t_list	*bstack = NULL;

// 	astack = ft_lstnew(0);
// 	ft_lstadd_back(&astack, ft_lstnew(1));
// 	ft_lstadd_back(&astack, ft_lstnew(2));

// 	bstack = ft_lstnew(100);
// 	ft_lstadd_back(&bstack, ft_lstnew(101));
// 	ft_lstadd_back(&bstack, ft_lstnew(102));

// 	pb(&astack, &bstack);
// 	print_stack(astack);
// 	print_stack(bstack);
// }