#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**nbrs;
	int		i;
	long	data;
	t_list	*node;
	t_list	**stack;

	i = 0;
	stack = NULL;
	stack = malloc(sizeof(t_list *));
	if (!stack)
		return (0);
	if (ac == 2)
		nbrs = ft_split(av[1], ' ');
	else
		nbrs = av + 1;
	if (!nbrs[0])
		error_exit(stack);
	if (!assign_index(stack))
		error_exit(stack);
	while (nbrs[i])
	{
		if (!is_valid_nb(nbrs[i]) || !is_int_range(nbrs[i]))
			error_exit(stack);
		data = ft_atol(nbrs[i]);
		if (has_dup(*stack, (int)data))
			error_exit(stack);
		if (is_sorted(stack))
			exit(0);
		node = ft_lstnew(data);
		ft_lstadd_back(stack, node);
		i++;
	}
}

// sort:
// if (size == 2)
// 	sort_2(astack);
// else if (size == 3)
// 	sort_3(astack);
// else if (size <= 5);
// 	sort_5(astack, bstack);
// else
// 	radix_sort(astack, bstack);
