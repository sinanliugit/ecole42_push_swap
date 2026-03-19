/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:58:16 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 16:04:24 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//记录栈顶；链接尾部；更新头指针;
void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_list **astack)
{
	rotate(astack);
	write(1, "ra\n", 3);
}

void	rb(t_list **bstack)
{
	rotate(bstack);
	write(1, "rb\n", 3);
}

void	rr(t_list **astack, t_list **bstack)
{
	rotate(astack);
	rotate(bstack);
	write(1, "rr\n", 3);
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

// 	//ra(&astack);
// 	//rb(&bstack);
// 	rr(&astack, &bstack);
// 	print_stack(astack);
// 	print_stack(bstack);
// }