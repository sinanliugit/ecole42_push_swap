/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:53:12 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 14:53:17 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	is_valid_nb(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == 0)
		return (0);
	if ((str[0] == '+' || str[0] == '-') && str[1] != 0)
		i++;
	else if (str[0] == '+' || str[0] == '-')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_int_range(char *str)
{
	long	nb;

	nb = ft_atol(str);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	return (1);
}

int	has_dup(t_list *stack, int data)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data == data)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

// fd = 2,stderr,错误输出
// exit 1: exit a false value;
void	error_exit(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	write(2, "Error\n", 6);
	exit(1);
}
