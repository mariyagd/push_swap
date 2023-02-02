/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:53:59 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 13:39:49 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*the function to sort 5 number is in file short_sorting_five.c
 * These functions are used if the very initial size of stack a is
 * >= 2 and <= 5 !
 *
 * sort_three() function is also used in big sorting.*/

void	sort_two(t_stack **s)
{
	if ((*s)->index_sorted < (*s)->next->index_sorted)
		ft_sb(s);
}

void	sort_three(t_stack **s)
{
	int		min;
	int		max;

	if (check_if_sorted(*s) == true)
		return ;
	max = find_max_index(*s);
	min = find_min_index(*s);
	if ((*s)->index_sorted == max && \
			(*s)->next->index_sorted == min)
		ft_ra(s);
	else if ((*s)->index_sorted == max && \
			(*s)->next->next->index_sorted == min)
	{
		ft_sa(s);
		ft_rra(s);
	}
	else if ((*s)->next->next->index_sorted == min)
		ft_rra(s);
	else if ((*s)->next->index_sorted == min)
		ft_sa(s);
	else
	{
		ft_rra(s);
		ft_sa(s);
	}
}

void	sort_four(t_stack **s1, t_stack **s2)
{
	int			min;

	min = find_min_index(*s1);
	if ((*s1)->index_sorted > (*s1)->next->index_sorted)
	{
		ft_sa(s1);
		if (check_if_sorted(*s1) == true)
			return ;
	}
	if ((*s1)->index_sorted == min)
		ft_pb(s1, s2);
	else
	{
		while ((*s1)->index_sorted != min)
		{
			ft_rra(s1);
			if (check_if_sorted(*s1) == true)
				return ;
		}
		ft_pb(s1, s2);
	}
	if (check_if_sorted(*s1) == false)
		sort_three(s1);
	ft_pa(s1, s2);
}

void	short_sorting(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}
