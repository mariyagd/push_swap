/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:23:35 by mdanchev          #+#    #+#             */
/*   Updated: 2023/01/30 14:20:41 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap_op(t_stack **s)
{
	t_stack	*ptr;

	if (!*s || (*s)->next == NULL)
		return ;
	ptr = (*s)->next;
	(*s)->next = ptr->next;
	ptr->next = *s;
	*s = ptr;
}

void	ft_sa(t_stack **a)
{
	swap_op(a);
	ft_printf("sa\n");
}

void	ft_sb(t_stack **b)
{
	swap_op(b);
	ft_printf("sb\n");
}

void	ft_ss(t_stack **a, t_stack **b)
{
	swap_op(a);
	swap_op(b);
	ft_printf("ss\n");
}
