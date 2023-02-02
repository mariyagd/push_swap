/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:47:42 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 12:48:56 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*find_lastnode(t_stack **head)
{
	t_stack	*ptr;

	ptr = *head;
	while (ptr != NULL && ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

int	stack_size(t_stack *ptr)
{
	int	size;

	size = 0;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		size++;
	}
	return (size);
}
