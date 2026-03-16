#include "push_swap.h"

// 5 functions
int	count_nodes(t_list *stack)
{
	t_list	*tmp;
	int		count;

	tmp = stack;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	fill_tab(t_list *stack, int *tab)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->data;
		i++;
		tmp = tmp->next;
	}
}

void	bubble_sort(int *tab, int count)
{
	int i, w, com;
	w = 0;
	while (w < count)
	{
		i = 0;
		while (i < count - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				com = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = com;
			}
			i++;
		}
		w++;
	}
}

void	assign_index_to_stack(t_list *stack, int *tab, int count)
{
	t_list	*tmp;
	int		i;

	tmp = stack;
	while (tmp)
	{
		i = 0;
		while (i < count)
		{
			if (tab[i] == tmp->data)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	assign_index(t_list *stack)
{
	int	count;
	int	*tab;

	count = count_nodes(stack);
	tab = malloc(sizeof(int) * count);
	if (!tab)
		return ;
	fill_tab(stack, tab);
	bubble_sort(tab, count);
	assign_index_to_stack(stack, tab, count);
	free(tab);
}

// int	main(void)
// {
// 	t_list	*stack;

// 	stack = ft_lstnew(104);
// 	ft_lstadd_back(&stack, ft_lstnew(103));
// 	ft_lstadd_back(&stack, ft_lstnew(102));
// 	ft_lstadd_back(&stack, ft_lstnew(101));

// 	assign_index(stack);
// 	while(stack)
// 	{
// 		printf("%d->", stack->index);
// 		stack = stack->next;
// 	}
// }