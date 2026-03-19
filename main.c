#include "push_swap.h"

//5functions
//check if it's sorted
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

//parsing
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

//build stack
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
//choose sort algo
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
		return (0);
	assign_index(astack);
	sort_algo(&astack, &bstack);
	return (0);
}

