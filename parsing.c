#include "push_swap.h"

// main function pass 25 lines!
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

// delete main function for is_sorted
// int	main(void)
// {
// 	t_list	*stack;

// 	stack = ft_lstnew(3);
// 	ft_lstadd_back(&stack, ft_lstnew(7));
// 	ft_lstadd_back(&stack, ft_lstnew(5));

// 	printf("%d\n", is_sorted(stack));
// }
