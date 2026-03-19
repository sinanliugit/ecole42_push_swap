/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:57:12 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 16:04:04 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// look for max_bits
// if bit == 0 -> pb; else -> ra (the end of the stack)
// find the biggest index, that's the max time to iterate

int	find_biggest_index(t_list **astack)
{
	int		max;
	t_list	*tmp;

	max = (*astack)->index;
	tmp = *astack;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	count_bits(t_list **astack)
{
	int	count;
	int	biggest_index;

	count = 0;
	biggest_index = find_biggest_index(astack);
	while (biggest_index >> count)
		count++;
	return (count);
}

// no need to mo//check if it's sorted
int	is_sorted(t_list *stack)
{
	t_list	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// no need iterate pointer,cause ra,pb is already moving 
// just see the head pointer
void	radix_sort(t_list **astack, t_list **bstack)
{
	int	count;
	int	i;
	int	w;
	int	size;

	i = 0;
	count = count_bits(astack);
	while (i < count)
	{
		w = 0;
		size = ft_lstsize(*astack);
		while (w < size)
		{
			if (((*astack)->index >> i) & 1)
				ra(astack);
			else
				pb(astack, bstack);
			w++;
		}
		while (*bstack)
			pa(astack, bstack);
		i++;
	}
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
// 	ft_lstadd_back(&astack, ft_lstnew(10));
//	ft_lstadd_back(&astack, ft_lstnew(5));
//	ft_lstadd_back(&astack, ft_lstnew(28));
//	ft_lstadd_back(&astack, ft_lstnew(46));
//	ft_lstadd_back(&astack, ft_lstnew(-9));

//	assign_index(astack);
//	radix_sort(&astack, &bstack);
//	print_stack (astack);
//	print_stack (bstack);
// }
