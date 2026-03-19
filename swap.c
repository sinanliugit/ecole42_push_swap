/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:59:39 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 16:04:54 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap top two of stack a
// the first next to the third
// the second next to the first
// update the head
void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_list **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

// swap top two of stack a and stack b the same time
void	ss(t_list **astack, t_list **bstack)
{
	swap(astack);
	swap(bstack);
	write(1, "ss\n", 3);
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

// 	astack = ft_lstnew(2);
// 	ft_lstadd_back(&astack, ft_lstnew(1));
// 	ft_lstadd_back(&astack, ft_lstnew(3));

// 	bstack = ft_lstnew(-2);
// 	ft_lstadd_back(&bstack, ft_lstnew(-1));
// 	ft_lstadd_back(&bstack, ft_lstnew(-3));

// 	ss(&astack, &bstack);
// 	print_stack (astack);
// 	print_stack (bstack);
// }