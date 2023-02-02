/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:06:50 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/02 15:06:53 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_median(t_stack *s)
{
	int	size;

	size = stack_size(s);
	size = (size + 1) / 2;
	return (size);
}
