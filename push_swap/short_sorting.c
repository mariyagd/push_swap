/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:53:59 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/03 13:18:34 by mdanchev         ###   lausanne.ch       */
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

void	short_sorting(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		small_sorting(a, b);
	else if (size == 5)
		sort_five(a, b);
}
