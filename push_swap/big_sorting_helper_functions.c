/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorting_helper_functions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 13:40:09 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 14:54:41 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	count_numbers(t_stack *s, int median)
{
	int	count;

	count = 0;
	while (s)
	{
		if (s->index_sorted < median)
			count++;
		s = s->next;
	}
	return (count);
}

int	median_big_sort(t_stack *s)
{
	int			i;
	int			size;
	int			*array;
	t_stack		*ptr;

	i = 0;
	size = stack_size(s);
	ptr = s;
	array = malloc(size * sizeof(int));
	if (!array)
		return (0);
	while (i < size && ptr != NULL)
	{
		array[i] = ptr->index_sorted;
		i++;
		ptr = ptr->next;
	}
	sort_int_tab(&array, (unsigned int)size);
	i = array[size / 4];
	free(array);
	return (i);
}

int	helper_function(t_stack *s, int median)
{
	int	i;
	int	middle;
	int	count_upper;
	int	count_lower;

	i = 0;
	count_upper = 0;
	count_lower = 0;
	middle = stack_size(s) / 2;
	while (s && i <= middle)
	{
		if (s->index_sorted < median)
			count_upper++;
		i++;
	}
	while (s && i < middle)
	{
		if (s->index_sorted < median)
			count_lower++;
		i++;
	}
	if (count_lower > count_upper)
		return (DO_RRA);
	else
		return (DO_RA);
}

int	helper(t_stack *s, int ind_search)
{
	int	middle;

	middle = stack_size(s) / 4;
	set_position(&s);
	while (s && s->index_sorted != ind_search)
		s = s->next;
	if (s->pos > middle)
		return (DO_RRB);
	return (0);
}

void	sort_stack_b(t_stack **s1, t_stack **s2)
{
	t_stack	*ptr;
	int		next;

	ptr = *s2;
	while (*s2)
	{
		ptr = find_lastnode(s2);
		next = (*s1)->index_sorted - 1;
		if ((*s2)->index_sorted == next)
			ft_pa(s1, s2);
		else if (ptr->index_sorted == next)
			ft_rrb(s2);
		else if ((*s2)->next->index_sorted == next)
			ft_sb(s2);
		else if (helper(*s2, next) == DO_RRB)
			ft_rrb(s2);
		else
			ft_rb(s2);
	}
}
