/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:58:46 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 16:04:33 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **astack)
{
	if (!astack || !(*astack) || !(*astack)->next)
		return ;
	if ((*astack)->data > (*astack)->next->data)
		sa(astack);
}

void	sort_3(t_list **astack)
{
	long	top;
	long	mid;
	long	end;

	top = (*astack)->data;
	mid = (*astack)->next->data;
	end = (*astack)->next->next->data;
	if (top < mid && mid > end && top < end)
	{
		sa(astack);
		ra(astack);
	}
	else if (top > mid && mid < end && top < end)
		sa(astack);
	else if (top < mid && mid > end && top > end)
		rra(astack);
	else if (top > mid && mid < end && top > end)
		ra(astack);
	else if (top > mid && mid > end && top > end)
	{
		sa(astack);
		rra(astack);
	}
}

// common fucntion for sort_4 and sort_5,find min_val and push to stack b
// min_index is the index of the nb after sorting
// i is the index of the number;
int	find_min_index(t_list *stack)
{
	t_list	*tmp;
	int		min;
	int		min_index;
	int		i;

	tmp = stack;
	min = tmp->index;
	min_index = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			min_index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_index);
}

// according to the position find the easiest way，
// rotate min_index times to the top;
void	push_min_to_b(t_list **astack, t_list **bstack)
{
	int	min_index;
	int	size;

	min_index = find_min_index(*astack);
	size = ft_lstsize(*astack);
	if (min_index <= size / 2)
	{
		while (min_index > 0)
		{
			ra(astack);
			min_index--;
		}
	}
	else
	{
		while (min_index < size)
		{
			rra(astack);
			min_index++;
		}
	}
	pb(astack, bstack);
}

// sort_4, handle min_val
// pay attention to src stack and dest stack
void	sort_4and5(t_list **astack, t_list **bstack)
{
	int	size;

	size = ft_lstsize(*astack);
	if (size == 4)
	{
		push_min_to_b(astack, bstack);
		sort_3(astack);
		pa(astack, bstack);
	}
	else if (size == 5)
	{
		push_min_to_b(astack, bstack);
		push_min_to_b(astack, bstack);
		sort_3(astack);
		pa(astack, bstack);
		pa(astack, bstack);
	}
}

/*
int	main(void)
{
	t_list	*astack;
	t_list	*bstack;

	bstack = NULL;
	astack = ft_lstnew(5);
	ft_lstadd_back(&astack, ft_lstnew(2));
	ft_lstadd_back(&astack, ft_lstnew(3));
	ft_lstadd_back(&astack, ft_lstnew(10));
	//ft_lstadd_back(&astack, ft_lstnew(-6));
	assign_index(astack);
	//sort_3(&astack);
	sort_4and5(&astack, &bstack);
	while (astack)
	{
		printf("%ld->", astack->data);
		astack = astack->next;
	}
	printf("null\n");
		while (bstack)
	{
		printf("%ld->", bstack->data);
		bstack = bstack->next;
	}
	printf("null\n");
}
*/