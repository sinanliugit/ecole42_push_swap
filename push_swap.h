/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siliu <siliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:57:22 by siliu             #+#    #+#             */
/*   Updated: 2026/03/19 16:02:30 by siliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long			data;
	int				index;
	struct s_list	*next;
}					t_list;

// assign_index
int					count_nodes(t_list *stack);
void				fill_tab(t_list *stack, int *tab);
void				bubble_sort(int *tab, int count);
void				assign_index_to_stack(t_list *stack, int *tab, int count);
void				assign_index(t_list *stack);

// check_error
int					ft_isdigit(int c);
int					is_valid_nb(char *str);
int					is_int_range(char *str);
int					has_dup(t_list *stack, int data);
void				error_exit(t_list **stack);

// ft_atol
long				ft_atol(const char *str);

// ft_lst
t_list				*ft_lstnew(long data);
int					ft_lstsize(t_list *stack);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);

// ft_split
int					count_words(const char *s, char c);
char				*fill_word(const char *s, int len, int start);
char				**ft_free(char **tab, int number);
char				**do_malloc(char const *s, char c);
char				**ft_split(char const *s, char c);

// push
void				push(t_list **src, t_list **dest);
void				pb(t_list **astack, t_list **bstack);
void				pa(t_list **astack, t_list **bstack);

// reverse_rotate
void				reverse_rotate(t_list **stack);
void				rra(t_list **astack);
void				rrb(t_list **bstack);
void				rrr(t_list **astack, t_list **bstack);

// rotate
void				rotate(t_list **stack);
void				ra(t_list **astack);
void				rb(t_list **bstack);
void				rr(t_list **astack, t_list **bstack);

// swap
void				swap(t_list **stack);
void				sa(t_list **stack);
void				sb(t_list **stack);
void				ss(t_list **astack, t_list **bstack);

// small_sort
void				sort_2(t_list **astack);
void				sort_3(t_list **astack);
int					find_min_index(t_list *stack);
void				push_min_to_b(t_list **astack, t_list **bstack);
void				sort_4and5(t_list **astack, t_list **bstack);

// radix_sort
int					is_sorted(t_list *stack);
int					find_biggest_index(t_list **astack);
int					count_bits(t_list **astack);
void				radix_sort(t_list **astack, t_list **bstack);

// main
char				**parse(int ac, char **av);
void				build_stack(t_list **stack, char **nbrs);
void				sort_algo(t_list **astack, t_list **bstack);

#endif