/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:35:45 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 13:36:03 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	helper_sort_five(t_stack **s1, t_stack **s2, int median)
{
	t_stack		*ptr;
	int			count;

	ptr = find_lastnode(s1);
	count = 1;
	while (ptr->index_sorted < median && count++ != median)
	{
		ft_rra(s1);
		ft_pb(s1, s2);
		ptr = find_lastnode(s1);
	}
	ptr = *s1;
	while (count != median)
	{
		if (ptr->index_sorted < median)
		{
			ft_pb(s1, s2);
			count++;
		}
		else
			ft_ra(s1);
		ptr = *s1;
	}
}

void	sort_five(t_stack **s1, t_stack **s2)
{
	int			median;
	t_stack		*ptr;

	ptr = find_lastnode(s1);
	median = find_median(*s1);
	helper_sort_five(s1, s2, median);
	sort_three(s1);
	sort_two(s2);
	ft_pa(s1, s2);
	ft_pa(s1, s2);
}
