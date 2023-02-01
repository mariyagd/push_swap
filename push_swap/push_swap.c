/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:10 by mdanchev          #+#    #+#             */
/*   Updated: 2023/02/01 17:56:20 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 * create_stack_a(char **av, t_stack **a);
 * if there are no arguments -> return nothing
 * if there are arguments -> check for errors
 * if there is only one string with one number
 *		-> return error
 *	if there is only one string with multiple numbers inside
 *		-> split the string
 *		-> prepare a linked list
 *		-> free the string
 *		-> return the linked list
 *	if there are multiple strings
 *		-> prepare a linked list
 *		-> return it
 */

void	check_if_sorted_and_exit(t_stack *s1, t_stack *s2, int size)
{
	int	i;

	i = 1;
	while (s1 && s1->index_sorted == i)
	{
		s1 = s1->next;
		i++;
	}
	if (--i == size && stack_size(s2) == 0)
		exit (0);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			size;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av++;
	a = create_stack_a(av, &a, &b);
	if (!a)
		return (0);
	size = stack_size(a);
	if (size >= 2 && size <= 5)
		short_sorting(&a, &b);
	if (size >= 6 && size <= 10)
		sort_less_than_ten(&a, &b);
	if (size >= 11 && size <= 500)
		small_sorting(&a, &b, size);
	check_if_sorted_and_exit(a, b, size);
	return (1);
}
