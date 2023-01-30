/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdanchev <mdanchev@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:25:10 by mdanchev          #+#    #+#             */
/*   Updated: 2023/01/30 17:27:25 by mdanchev         ###   lausanne.ch       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
/*
 * create_stack_a(char **av, t_stack **a);
 * if there are no arguments -> return nothing
 * if there are arguments -> check for errors
 * if there is only one string with one number and no errors
 *		-> create a new node only and exit the program
 *	if there is only one string with multiple numbers inside
 *		-> split the string
 *		-> prepare a linked list
 *		-> free
 *		-> return the linked list
 *	if there are multiple strings
 *		-> prepare a linked list
 *		-> return it
 */


//A CACHER
void	print_index(t_stack *a)
{
	ft_printf("index\n");
	while (a)
	{
		ft_printf("%d\n", a->index_sorted);
		a = a->next;
	}
}
//A CACHER
void	print_stack(t_stack *a)
{
	ft_printf("stack\n");
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
}


void	check_if_sorted_and_exit(t_stack	*s, int size)
{
	int	i;

	i = 1;
	while (s && s->index_sorted == i)
	{
		s = s->next;
		i++;
	}
	if (--i == size)
		exit (0);
}


void	sort_three(t_stack **s)
{
	int		min;
	int		max;

	max = find_max_index(*s);
	min = find_min_index(*s);
	if ((*s)->index_sorted == max && \
			(*s)->next->index_sorted == min)
		ft_ra(s);
	else if ((*s)->next->index_sorted == min && \
			(*s)->next->next->index_sorted == max)
		ft_sa(s);
	else if ((*s)->index_sorted == max && \
			(*s)->next->next->index_sorted == min)
	{
		ft_sa(s);
		ft_rra(s);
	}
	else if ((*s)->next->next->index_sorted == min)
		ft_rra(s);
	else
	{
		ft_rra(s);
		ft_sa(s);
	}
	//check_if_sorted_and_exit(*s, 3);
}

int find_median(t_stack *s)
{
	int	size;

	size = stack_size(s);
	size = (size + 1) / 2;
	return (size);
}

void	sort_five(t_stack **s1, t_stack **s2)
{
	int	median;
	t_stack	*ptr;
	int	count;

	ptr = *s1;
	count = 1;
	median = find_median(*s1);
	while (count != median)
	{
		if (ptr->index_sorted < median)
		{
			ft_pb(s1, s2);
			count++;
		}
		else
			ft_ra(s1);
		ptr = *s1;
	}
	sort_three(s1);
	print_stack(*s1);
	if ((*s2)->index_sorted < (*s2)->next->index_sorted)
		ft_sb(s2);
	ft_pa(s1, s2);
	ft_pa(s1, s2);
}

		
void	short_sorting(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
	{
		ft_sa(a);
		exit(0);
	}
	if (size == 3)
		sort_three(a);
	if (size == 4)
		sort_four(a, b);
	if (size == 5)
		sort_five(a, b);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av++;
	a = create_stack_a(av, &a);
	if (!a)
		return (0);
	short_sorting(&a, &b);

	//TEST INDEX MIN ET MAX
	ft_printf("INDEX MAX = %d\n", find_max_index(a));
	ft_printf("INDEX MIN = %d\n", find_min_index(a));

	//tests
	print_stack(a);
	print_index(a);
	print_stack(b);
	print_index(b);
}




