/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:03:59 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 14:39:20 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	first_condition(t_stack **s1, t_stack **s2, int median, int *i)
{
	t_stack	*ptr;

	ft_pb(s1, s2);
	(*i)++;
	ptr = find_lastnode(s2);
	if (stack_size(*s2) >= 2 && (*s2)->index_sorted < \
			(*s2)->next->index_sorted && (*s2)->index_sorted > median / 2 && \
			(*s2)->next->index_sorted > median / 2)
		ft_sb(s2);
	if (stack_size(*s2) >= 2 && (*s2)->index_sorted < median / 2)
		ft_rb(s2);
	if (stack_size(*s2) >= 2 && ptr->index_sorted > (*s2)->index_sorted)
		ft_rrb(s2);
}

void	big_sorting(t_stack **s1, t_stack **s2)
{
	int			median;
	int			count;
	int			i;
	t_stack		*ptr;

	while (stack_size(*s1) > 3 && check_if_sorted(*s1) == false)
	{
		median = median_big_sort(*s1);
		count = count_numbers(*s1, median);
		i = 0;
		while (i != count && check_if_sorted(*s1) == false \
				&& stack_size(*s1) > 3)
		{
			ptr = find_lastnode(s1);
			if ((*s1)->index_sorted < median)
				first_condition(s1, s2, median, &i);
			else if (ptr->index_sorted < median)
				ft_rra(s1);
			else
				ft_ra(s1);
		}
	}
	sort_three(s1);
	sort_stack_b(s1, s2);
}
