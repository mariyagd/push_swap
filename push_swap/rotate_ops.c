/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:52:23 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 12:52:38 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rotate_op(t_stack **s)
{
	t_stack	*end;
	t_stack	*start;

	if (!*s || (*s)->next == NULL)
		return ;
	start = *s;
	*s = (*s)->next;
	end = *s;
	while (end->next)
	{
		end = end->next;
	}
	end->next = start;
	start->next = NULL;
}

void	ft_rb(t_stack **b)
{
	rotate_op(b);
	ft_printf("rb\n");
}

void	ft_ra(t_stack **a)
{
	rotate_op(a);
	ft_printf("ra\n");
}

void	ft_rr(t_stack **a, t_stack **b)
{
	rotate_op(a);
	rotate_op(b);
	ft_printf("rr\n");
}
