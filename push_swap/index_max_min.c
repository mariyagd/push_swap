/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_max_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:29:05 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 12:29:08 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_max_index(t_stack *s)
{
	t_stack		*ptr;
	int			max;

	ptr = s;
	max = ptr->index_sorted;
	while (ptr)
	{
		if (ptr->index_sorted > max)
			max = ptr->index_sorted;
		ptr = ptr->next;
	}
	return (max);
}

int	find_min_index(t_stack *s)
{
	t_stack		*ptr;
	int			min;

	ptr = s;
	min = ptr->index_sorted;
	while (ptr)
	{
		if (ptr->index_sorted < min)
			min = ptr->index_sorted;
		ptr = ptr->next;
	}
	return (min);
}
