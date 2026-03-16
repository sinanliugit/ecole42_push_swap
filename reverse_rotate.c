#include "push_swap.h"

//遍历到倒数第二个元素；更新next指针让尾部元素变栈顶
// need two pointers , one change , one point to null
// 4 functions
void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*pre_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	pre_last = NULL;
	while (last->next)
	{
		pre_last = last;
		last = last->next;
	}
	pre_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_list **astack)
{
	reverse_rotate(astack);
	write(1, "rra\n", 4);
}

void	rrb(t_list **bstack)
{
	reverse_rotate(bstack);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **astack, t_list **bstack)
{
	reverse_rotate(astack);
	reverse_rotate(bstack);
	write(1, "rrr\n", 4);
}

// delete aide printf function
// void	print_stack(t_list *stack)
// {
// 	while (stack)
// 	{
// 		printf("%ld -> ", stack->data);
// 		stack = stack->next;
// 	}
// 	printf("NULL\n");
// }

// delete test main
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

// 	//rra(&astack);
// 	//rrb(&bstack);
// 	rrr(&astack, &bstack);
// 	print_stack(astack);
// 	print_stack(bstack);
// }