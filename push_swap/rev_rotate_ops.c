/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:51:54 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 12:51:57 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rev_rotate(t_stack **s)
{
	t_stack	*end;
	t_stack	*prev;
	t_stack	*head;

	if (!*s || (*s)->next == NULL)
		return ;
	head = *s;
	end = *s;
	while (end->next)
	{
		prev = end;
		end = end->next;
	}
	prev->next = NULL;
	end->next = head;
	*s = end;
}

void	ft_rrb(t_stack **b)
{
	rev_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rra(t_stack **a)
{
	rev_rotate(a);
	ft_printf("rra\n");
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
}
