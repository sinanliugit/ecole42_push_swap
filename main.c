/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:55:56 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 14:55:58 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse(int ac, char **av)
{
	char	**nbrs;

	if (ac == 2)
		nbrs = ft_split(av[1], ' ');
	else
		nbrs = av + 1;
	if (!nbrs || !nbrs[0])
		error_exit(NULL);
	return (nbrs);
}

void	build_stack(t_list **stack, char **nbrs)
{
	int		i;
	long	data;
	t_list	*node;

	i = 0;
	while (nbrs[i])
	{
		if (!is_valid_nb(nbrs[i]) || !is_int_range(nbrs[i]))
			error_exit(stack);
		data = ft_atol(nbrs[i]);
		if (has_dup(*stack, (int)data))
			error_exit(stack);
		node = ft_lstnew(data);
		ft_lstadd_back(stack, node);
		i++;
	}
}

void	sort_algo(t_list **astack, t_list **bstack)
{
	int	size;

	size = ft_lstsize(*astack);
	if (size <= 5)
	{
		if (size == 2)
			sort_2(astack);
		else if (size == 3)
			sort_3(astack);
		else if (size == 4 || size == 5)
			sort_4and5(astack, bstack);
	}
	else
		radix_sort(astack, bstack);
}

void	ft_freestack(t_list **astack, t_list **bstack)
{
	t_list	*tmp1;
	t_list	*tmp2;

	while (*astack)
	{
		tmp1 = (*astack)->next;
		free(*astack);
		*astack = tmp1;
	}
	*astack = NULL;
	while (*bstack)
	{
		tmp2 = (*bstack)->next;
		free(*bstack);
		*bstack = tmp2;
	}
}

// main
int	main(int ac, char **av)
{
	t_list	*astack;
	t_list	*bstack;
	char	**nbrs;

	if (ac < 2)
		return (0);
	astack = NULL;
	bstack = NULL;
	nbrs = parse(ac, av);
	build_stack(&astack, nbrs);
	if (is_sorted(astack))
	{
		ft_freestack(&astack, &bstack);
		return (0);
	}
	assign_index(astack);
	sort_algo(&astack, &bstack);
	ft_freestack(&astack, &bstack);
	return (0);
}
