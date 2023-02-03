/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:40:09 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/03 13:19:47 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_pos(t_stack *s, int min)
{
	while (s && s->index_sorted != min)
		s = s->next;
	return (s->pos);
}

void	small_sorting(t_stack **s1, t_stack **s2)
{
	int	min;
	int	middle;
	int	pos;

	while (stack_size(*s1) > 3 && check_if_sorted(*s1) == false)
	{
		min = find_min_index(*s1);
		middle = stack_size(*s1) / 2;
		pos = find_pos(*s1, min);
		if (pos >= middle)
			while ((*s1)->index_sorted != min && check_if_sorted(*s1) == false)
				ft_rra(s1);
		else
			while ((*s1)->index_sorted != min && check_if_sorted(*s1) == false)
				ft_ra(s1);
		if ((*s1)->index_sorted == min && check_if_sorted(*s1) == false)
		{
			ft_pb(s1, s2);
			set_position(s1);
		}
	}
	if (stack_size(*s1) == 3)
		sort_three(s1);
	while (*s2)
		ft_pa(s1, s2);
}
